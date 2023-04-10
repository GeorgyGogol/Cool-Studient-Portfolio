#include "gcell.h"

GCell::GCell(automat::cCell* p_cell) :
    QGraphicsObject(nullptr),
    pCell(p_cell)
{
}

bool GCell::askCanChange() {
    bool out = false;

    emit getCanChangeState(out, this);

    return out;
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

	QRectF dCell = boundingRect();
    painter->setPen(Qt::black);
    painter->drawRect(dCell);

    if (pCell->getStatus()) {
        painter->setBrush(Qt::black);

		dCell.setX(dCell.x() + 2);
		dCell.setWidth(dCell.width() - dCell.x());
		dCell.setY(dCell.y() + 2);
		dCell.setHeight(dCell.height() - dCell.y());

        painter->drawRect(dCell);
    }

    painter->restore();
}

void GCell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (askCanChange()) {
        pCell->switchStatus();
    }

    QGraphicsItem::mousePressEvent(event);
}


