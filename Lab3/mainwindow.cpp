#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QJsonObject>
#include <QPushButton>
#include <QDebug>
#include <QLabel>

QJsonDocument LoadHierarchyFromJSON()
{
    QString val;
    QFile file;
    file.setFileName(":data.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    return QJsonDocument::fromJson(val.toUtf8());
}

void ClearLayout(QLayout *layout) {
    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            ClearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_JsonDoc = LoadHierarchyFromJSON();
    m_DepartmentsList = GetDepartmentsList();
    CreateDepartmentsInfoButtons();

}

void MainWindow::AppendTeacherInfo(QJsonValueRef el)
{
    QLabel *teacherInfo = new QLabel();
    ui->teachersInfoLayout->addWidget(teacherInfo);
    teacherInfo->setText(teacherInfo->text() + el.toObject()["surname"].toString() + "\n");
    teacherInfo->setText(teacherInfo->text() + el.toObject()["name"].toString() + "\n");
    teacherInfo->setText(teacherInfo->text() + el.toObject()["patronymic"].toString() + "\n");
    teacherInfo->setText(teacherInfo->text() + el.toObject()["department"].toString() + "\n");
    teacherInfo->setText(teacherInfo->text() + el.toObject()["jobTitle"].toString() + "\n");


    QLabel *labelImage = new QLabel();
    ui->teachersInfoLayout->addWidget(labelImage);
    QPixmap pixmap(":/images/" + el.toObject()["image"].toString());
    labelImage->setPixmap(pixmap.scaledToWidth(200));
    labelImage->show();
}

void MainWindow::CreateDepartmentsInfoButtons()
{
    for(auto department : m_DepartmentsList)
    {
        QPushButton *departmentButton = new QPushButton();
        departmentButton->setText(department);
        QListWidgetItem* departmentButtonItem = new QListWidgetItem(ui->departmentsList);
        QObject::connect(departmentButton, &QPushButton::clicked, [=]() {
            ClearLayout(ui->teachersInfoLayout);
            for (auto el : m_JsonDoc.object())
                if(el.toObject()["department"].toString() == departmentButton->text())
                    AppendTeacherInfo(el);
        });
        ui->departmentsList->setItemWidget(departmentButtonItem, departmentButton);
    }
}

QVector<QString> MainWindow::GetDepartmentsList()
{
    QVector<QString> departments;
    for (auto el : m_JsonDoc.object())
        departments.push_back(el.toObject()["department"].toString());
    // Remove identical
    std::sort(departments.begin(), departments.end());
    departments.erase(std::unique(departments.begin(), departments.end()), departments.end());
    return departments;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_searchButton_clicked()
{
    ClearLayout(ui->teachersInfoLayout);
    for (auto el : m_JsonDoc.object())
        if(ui->searchInput->toPlainText().toLower() == el.toObject()["surname"].toString().toLower())
            AppendTeacherInfo(el);
}

