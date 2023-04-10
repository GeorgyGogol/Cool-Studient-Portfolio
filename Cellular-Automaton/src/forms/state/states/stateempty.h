#ifndef STATEEMPTY_H
#define STATEEMPTY_H

#include "iwinstate.h"
#include "windowpointkeeper.h"
#include <QMainWindow>

namespace states {

class StateEmpty :
        public IWinState,
        public WindowPointKeeper<QMainWindow>
{
public:
    StateEmpty(QMainWindow* pWindow);
    virtual ~StateEmpty() override;

public:
    void Enter() override;
    void Exit() override;

    bool isRunning() const override;

};

}

#endif // STATEEMPTY_H
