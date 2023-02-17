#include "graphicswatcharea.h"

#include <QMouseEvent>

GraphicsWatchArea::GraphicsWatchArea(QWidget *parent) :
    QGraphicsView(parent)
{
}

GraphicsWatchArea::GraphicsWatchArea(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene, parent)
{
}

void GraphicsWatchArea::mousePressEvent(QMouseEvent* event)
{
    emit GraphicsWatchArea::MouseClickedAt(event->x(), event->y());
    emit GraphicsWatchArea::MouseClickedAt(event);
    QGraphicsView::mousePressEvent(event);
}

void GraphicsWatchArea::mouseMoveEvent(QMouseEvent* event)
{
    emit MouseNowAt(event->x(), event->y());
    QGraphicsView::mouseMoveEvent(event);
}
