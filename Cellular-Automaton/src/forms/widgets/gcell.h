#ifndef GCELL_H
#define GCELL_H

#include <QGraphicsObject>
#include <QPainter>
#include "ccell.h"


class GCell :
        public QGraphicsObject
{
    Q_OBJECT

public:
    explicit GCell(automat::cCell* p_cell);

signals:
    void getCanChangeState(bool& state, const GCell* pSelf);

private:
    automat::cCell* pCell;

    bool askCanChange();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // GCELL_H
