#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "iwinstate.h"
#include <QMainWindow>
#include "windowpointkeeper.h"

#include "stateempty.h"
#include "statewithfield.h"
#include "staterun.h"
#include "stategameover.h"

namespace states {

class StateManager :
        public WindowPointKeeper<QMainWindow>
{
public:
    StateManager(QMainWindow* pWindow);
    ~StateManager();

private:
    IWinState* CurrentState;

    void ExitCurrent();

public:
    template<class TyState> void SetState()
    {
        ExitCurrent();
        CurrentState = new TyState(PWindow);
        CurrentState->Enter();
    }

    inline void SetStateEmpty() { SetState<StateEmpty>(); }
    inline void SetStateWithField() { SetState<StateWithField>(); }
    inline void SetStateIsRunning() { SetState<StateRun>(); }

    bool isRunning();

};

}

#endif // STATEMANAGER_H
