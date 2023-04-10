#ifndef CONTROLLEDGRIDSCENE_H
#define CONTROLLEDGRIDSCENE_H

#include <QGraphicsScene>
#include "gcell.h"
//#include <QTimer>

class ControlledGridScene :
        public QGraphicsScene
{
	Q_OBJECT

public:
    ControlledGridScene(QObject *parent = nullptr);

private:
    //QGraphicsItem* pCurrentView;
	//bool pressedState;
	GCell* pLastCell;
	//QTimer* WatchTimer;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

public:
    bool canChange;

    void createCellAt(int x, int y, automat::cCell* pCell);

public slots:
    void switchCanChangeStatus();
    void retCanChangeState(bool& state, const GCell* pEmitter = nullptr);
	//void sendMousePressEvent();

};

#endif // CONTROLLEDGRIDSCENE_H
