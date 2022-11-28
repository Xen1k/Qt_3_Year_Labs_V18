#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(QPixmap(":/1.jpg").scaled(w,h,Qt::KeepAspectRatio));
    ui->image1->setPixmap(QPixmap(":/2.jpg").scaled(w,h,Qt::KeepAspectRatio));
    ui->image2->setPixmap(QPixmap(":/3.jpg").scaled(w,h,Qt::KeepAspectRatio));
    ui->image3->setPixmap(QPixmap(":/4.jpg").scaled(w,h,Qt::KeepAspectRatio));
    ui->image4->setPixmap(QPixmap(":/5.jpg").scaled(w,h,Qt::KeepAspectRatio));
    ui->image5->setPixmap(QPixmap(":/6.jpg").scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

