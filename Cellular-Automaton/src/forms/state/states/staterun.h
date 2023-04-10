#ifndef STATERUN_H
#define STATERUN_H

#include "iwinstate.h"
#include "windowpointkeeper.h"
#include <QMainWindow>

#include <QTimer>

namespace states {

class StateRun :
        public QObject,
        public IWinState,
        public WindowPointKeeper<QMainWindow>
{
    Q_OBJECT

public:
    StateRun(QMainWindow* pWindow);
    virtual ~StateRun() override;

private:
    QTimer* BuzyUpdateTimer;

public:
    void Enter() override;
    void Exit() override;

    bool isRunning() const override;

public slots:
    void SetSpeedModyfier(double val);

};

}

#endif // STATERUN_H
