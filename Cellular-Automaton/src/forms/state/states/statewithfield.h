#ifndef STATEWITHFIELD_H
#define STATEWITHFIELD_H

#include "iwinstate.h"
#include "windowpointkeeper.h"
#include <QMainWindow>

#include <QTimer>

namespace states {

class StateWithField :
        public IWinState,
        public WindowPointKeeper<QMainWindow>
{
public:
    StateWithField(QMainWindow* pWindow);
    virtual ~StateWithField() override;

private:
    QTimer* LazyUpdateTimer;

public:
    void Enter() override;
    void Exit() override;

    bool isRunning() const override;

};

}

#endif // STATEWITHFIELD_H
