#ifndef GCELL_H
#define GCELL_H


#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include "../../automat/ccell.h"


class GCell :
        //public QObject,
        public QGraphicsItem
        //public automat::cCell
{
    //Q_OBJECT

public:
    explicit GCell(automat::cCell* p_cell, /*QObject *parentObject = nullptr,*/ QGraphicsItem* parentGrahpics = nullptr);

private:
    automat::cCell* pCell;
    bool CanChange;

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    void setCanChangeState(bool State);


};

#endif // GCELL_H
