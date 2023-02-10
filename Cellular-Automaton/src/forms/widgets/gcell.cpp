#include "gcell.h"

GCell::GCell(automat::cCell* p_cell, QGraphicsItem* parentGrahpics) :
    /*QObject(nullptr),*/
    QGraphicsItem(parentGrahpics),
    pCell(p_cell), CanChange(false)
{
}

QRectF GCell::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void GCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();

    painter->setPen(Qt::black);
    painter->drawRect(boundingRect());

    if (pCell->getStatus()) {
        painter->setBrush(Qt::black);
        QRect rect(2, 2, 46, 46);
        painter->drawRect(rect);
    }

    painter->restore();
}

void GCell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!CanChange) return;

    pCell->switchStatus();

    QGraphicsItem::mousePressEvent(event);
}

void GCell::setCanChangeState(bool State)
{
    CanChange = State;
}

