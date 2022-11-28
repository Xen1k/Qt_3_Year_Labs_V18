#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QGraphicsItem>
#include <QPainter>
#include "selectableListedObject.h"

class DigitalClock : public QGraphicsItem, public SelectableListedObject, public QObject
{
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
public:
    DigitalClock();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // DIGITALCLOCK_H
