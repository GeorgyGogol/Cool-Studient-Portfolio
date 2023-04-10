#include "stategameover.h"
#include <QMessageBox>
#include "statewithfield.h"
#include "mainwindow.h"

namespace states {

StateGameOver::StateGameOver(QMainWindow* pWindow) :
    WindowPointKeeper<QMainWindow>(pWindow)
{

}

StateGameOver::~StateGameOver()
{}

void StateGameOver::Enter()
{
    {
        StateWithField* pTmp = new StateWithField(PWindow);
        pTmp->Enter();
        delete pTmp;
    }

	static_cast<MainWindow*>(PWindow)->UpdateTick();

    QMessageBox::information(PWindow, "Внимание!", "Игра окончена!");
}

void StateGameOver::Exit()
{
}

bool StateGameOver::isRunning() const {
    return false;
}

}
