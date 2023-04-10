#ifndef STATEGAMEOVER_H
#define STATEGAMEOVER_H

#include "iwinstate.h"
#include "windowpointkeeper.h"
#include <QMainWindow>

namespace states {

class StateGameOver :
        public IWinState,
        public WindowPointKeeper<QMainWindow>
{
public:
    StateGameOver(QMainWindow* pWindow);
    virtual ~StateGameOver() override;

public:
    void Enter() override;
    void Exit() override;

    bool isRunning() const override;

};

}

#endif // STATEGAMEOVER_H
