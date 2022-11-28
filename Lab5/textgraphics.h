#ifndef TEXTGRAPHICS_H
#define TEXTGRAPHICS_H

#include <QGraphicsItem>
#include <QPainter>
#include "selectableListedObject.h"


class TextGraphics  : public QGraphicsItem, public SelectableListedObject
{
private:
    QString m_Text;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
public:
    TextGraphics(QString text);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // TEXTGRAPHICS_H
