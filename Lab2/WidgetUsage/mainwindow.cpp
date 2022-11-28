#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <build-DigitalClock-Desktop_Qt_5_12_12_MSVC2015_64bit-Release/../../DigitalClock/digitalclock.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DigitalClock *clock = new DigitalClock();
    connect(clock, SIGNAL(timeout()), this, SLOT(OnTimerSignalTriggered()));
    this->layout()->addWidget(clock);
}

void MainWindow::OnTimerSignalTriggered()
{
    qDebug() << "Signal triggered";
}

MainWindow::~MainWindow()
{
    delete ui;
}

