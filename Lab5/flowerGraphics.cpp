#include "flowerGraphics.h"
#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <QVector>
#include "mainwindow.h"
#include "ui_mainwindow.h"

FlowerGraphics::FlowerGraphics() : SelectableListedObject::SelectableListedObject("Flower", this)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

void FlowerGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::RightButton)
        HightlightObjectsButton();
}

void FlowerGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isSelected())
    {
        painter->drawText(0,0 , "Selected...");
        return;
    }
    painter->eraseRect(-100, -100, 100, 100);
    painter->setPen(QColor(100, 200, 100));
    painter->drawLine(QLine(0, 0, 0, 120));

    QVector<QPoint> points;

    int number_of_chunks = 6;
    double degrees = 0;
    double radius = 50;

    for (int i = 0; i < number_of_chunks; i++)
    {
        degrees = i * (360 / number_of_chunks);
        float radian = (degrees * (3.14f / 180));
        points.append(QPoint(0, 0));
        points.append(QPoint(radius * cos(radian), radius * sin(radian)));
    }
    for (int i = 0; i < number_of_chunks * 2 - 3; i+=4)
    {
        points.append(points[i+1]);
        points.append(points[i+3]);
    }

    painter->drawLines(points);
}

QRectF FlowerGraphics::boundingRect() const
{
    return QRectF(-50, -50, 100, 100);
}
