#ifndef FLOWERGRAPHICS_H
#define FLOWERGRAPHICS_H

#include <QGraphicsItem>
#include <QPainter>
#include "selectableListedObject.h"

class FlowerGraphics: public QGraphicsItem, public SelectableListedObject
{
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
public:
    FlowerGraphics();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // FLOWERGRAPHICS_H
