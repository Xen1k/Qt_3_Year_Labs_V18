#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalClock.h"
#include "textgraphics.h"
#include "flowerGraphics.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow& MainWindow::GetInstance()
{
    static MainWindow instance;
    return instance;
};

void MainWindow::on_addClockButton_clicked()
{
    scene->addItem(new DigitalClock());
}




void MainWindow::on_diselectButton_clicked()
{
    SelectableListedObject::DiselectLast();
}


void MainWindow::on_addTextButton_clicked()
{
    scene->addItem(new TextGraphics("ЕРЕСЬ!"));
}


void MainWindow::on_addFlowerButton_clicked()
{
    scene->addItem(new FlowerGraphics());
}

