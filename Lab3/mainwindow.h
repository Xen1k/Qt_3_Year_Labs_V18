#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    QJsonDocument m_JsonDoc;
    QVector<QString> m_DepartmentsList;
    void MainWindow::AppendTeacherInfo(QJsonValueRef el);
    QVector<QString> MainWindow::GetDepartmentsList();
    void CreateDepartmentsInfoButtons();

};
#endif // MAINWINDOW_H
