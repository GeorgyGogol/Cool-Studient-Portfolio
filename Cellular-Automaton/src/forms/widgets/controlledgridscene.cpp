#include "controlledgridscene.h"
#include "gcell.h"

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

ControlledGridScene::ControlledGridScene(QObject* parent) :
	QGraphicsScene(parent),
	//pressedState(false),
	pLastCell(nullptr),
	//WatchTimer(new QTimer(this)),
    canChange(false)
{
	//WatchTimer->setInterval(250);
	//connect(WatchTimer, &QTimer::timeout, this, &ControlledGridScene::sendMousePressEvent);
}

void ControlledGridScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsScene::mousePressEvent(event);
	//WatchTimer->start();
}

void ControlledGridScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	//WatchTimer->stop();
	QGraphicsScene::mouseReleaseEvent(event);
}

void ControlledGridScene::switchCanChangeStatus()
{
    canChange = !canChange;
}

void ControlledGridScene::createCellAt(int x, int y, automat::cCell* pCell)
{
    GCell* Cell = new GCell(pCell);
    Cell->setY(y * 50);
    Cell->setX(x * 50);

    connect(Cell, &GCell::getCanChangeState, this, &ControlledGridScene::retCanChangeState);

    addItem(Cell);
}

void ControlledGridScene::retCanChangeState(bool& state, const GCell* pEmitter)
{
	state = canChange;
	//if (WatchTimer->isActive()) state = state && pEmitter != pLastCell;

	if (state && pEmitter) pLastCell = const_cast<GCell*>(pEmitter);
}

/*
void ControlledGridScene::sendMousePressEvent()
{
	QGraphicsSceneMouseEvent* event = new QGraphicsSceneMouseEvent();
	event->setPos(QPoint(1, 1));
	QGraphicsScene::mousePressEvent(event);
	delete event;
}
*/

