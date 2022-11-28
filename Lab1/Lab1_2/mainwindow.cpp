#include "mainwindow.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow()
{
    InitializeWindow();

    m_TabWidget = new QTabWidget();
    m_layout->addWidget(m_TabWidget);
    QWidget* storeTab = new QWidget();
    QGridLayout* storeTabLayout = new QGridLayout();
    storeTab->setLayout(storeTabLayout);

    storeTabLayout->addWidget(GetGameCard("Garry's Mod", "1.jpg"), 0, 0);
    storeTabLayout->addWidget(GetGameCard("Half-Life", "2.jpg"), 1, 0);
    storeTabLayout->addWidget(GetGameCard("CS:GO", "3.jpg"), 0, 1);
    storeTabLayout->addWidget(GetGameCard("Valorant", "4.jpg"), 1, 1);
    storeTabLayout->addWidget(GetGameCard("GTA V", "5.jpg"), 0, 2);
    storeTabLayout->addWidget(GetGameCard("TES 5: Skyrim", "6.jpg"), 1, 2);

    m_TabWidget->addTab(storeTab, "Новинки");
    m_TabWidget->addTab(new QWidget(), "Популярное");
}

QWidget* MainWindow::GetGameCard(QString title, QString image)
{
    QWidget* card = new QWidget();
    card->setLayout(new QVBoxLayout());
    card->layout()->addWidget(new QLabel(title));

    QLabel *imageLabel = new QLabel();
    imageLabel->setPixmap(QPixmap(":/" + image).scaled(320, 180, Qt::KeepAspectRatio));
    card->layout()->addWidget(imageLabel);

    card->layout()->addWidget(new QPushButton("9.99$"));
    return card;
}

void MainWindow::InitializeWindow()
{
    m_window = new QWidget();
    m_window->resize(800, 600);
    m_window->setWindowTitle("Store");

    m_layout = new QGridLayout();
    m_window->setLayout(m_layout);
}


void MainWindow::Show() { m_window->show(); }

