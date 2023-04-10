#include "statemanager.h"

namespace states {

StateManager::StateManager(QMainWindow* pWindow) :
    WindowPointKeeper<QMainWindow>(pWindow),
    CurrentState(nullptr)
{
}

StateManager::~StateManager()
{
    ExitCurrent();
    PWindow = nullptr;
}

void StateManager::ExitCurrent()
{
    if (CurrentState){
        CurrentState->Exit();
        delete CurrentState;
        CurrentState = nullptr;
    }
}

bool StateManager::isRunning() 
{
    return CurrentState->isRunning();
}

}

