#include "mousepoint.h"

#include <QPainter>

MousePoint::MousePoint(QGraphicsItem* parentGrahpics) :
    QGraphicsItem(parentGrahpics),
    MouseButtion(Qt::MouseButton::NoButton)
{
}

QRectF MousePoint::boundingRect() const
{
    return QRectF(-5, -5, 5, 5);
}

void MousePoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::black);

    if (MouseButtion != Qt::MouseButton::NoButton)
    {
        if (MouseButtion == Qt::MouseButton::LeftButton)
        {
            painter->setBrush(Qt::blue);
        }
        else if (MouseButtion == Qt::MouseButton::RightButton)
        {
            painter->setBrush(Qt::red);
        }
    }

    painter->drawEllipse(boundingRect());

    painter->restore();
}

