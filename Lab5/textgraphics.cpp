#include "textgraphics.h"
#include <QGraphicsSceneMouseEvent>
#include <QColor>

TextGraphics::TextGraphics(QString text) : SelectableListedObject::SelectableListedObject(text, this), m_Text(text)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

void TextGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::RightButton)
        HightlightObjectsButton();
}

void TextGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(255, 0, 0));
    painter->drawText(0, 0, m_Text);
}

QRectF TextGraphics::boundingRect() const
{
    return QRectF(-50, -50, 100, 100);
}
