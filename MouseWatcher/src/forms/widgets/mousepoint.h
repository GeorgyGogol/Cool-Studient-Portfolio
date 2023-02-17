#ifndef MOUSEPOINT_H
#define MOUSEPOINT_H


#include <QGraphicsItem>

class MousePoint : public QGraphicsItem
{
public:
    MousePoint(QGraphicsItem* parentGrahpics = nullptr);

private:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    Qt::MouseButton MouseButtion;

};

#endif // MOUSEPOINT_H
