#include "digitalClock.h"
#include <QTime>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"

DigitalClock::DigitalClock() : SelectableListedObject::SelectableListedObject("Clock", this)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, [=]() { MainWindow::GetInstance().ui->graphicsView->viewport()->repaint(); });
    timer->start(1000);
}

void DigitalClock::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::RightButton)
        HightlightObjectsButton();
}

void DigitalClock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QTime time = QTime::currentTime();
    painter->drawText(0, 0, time.toString("hh:mm:ss"));
}

QRectF DigitalClock::boundingRect() const
{
    return QRectF(-50, -50, 100, 100);
}
