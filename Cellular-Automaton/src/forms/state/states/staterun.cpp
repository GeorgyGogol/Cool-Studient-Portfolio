#include "staterun.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>

#define BASE_TIMER_INTERVAL 500

namespace states {

StateRun::StateRun(QMainWindow* pWindow) :
    QObject(pWindow),
    WindowPointKeeper<QMainWindow>(pWindow),
    BuzyUpdateTimer(new QTimer(pWindow))
{
    MainWindow* pTrueWindow = static_cast<MainWindow*>(PWindow);

    BuzyUpdateTimer->setInterval(BASE_TIMER_INTERVAL);
    QObject::connect(BuzyUpdateTimer, &QTimer::timeout, pTrueWindow, &MainWindow::StepTick);
    QObject::connect(BuzyUpdateTimer, &QTimer::timeout, pTrueWindow, &MainWindow::UpdateTick);

    QObject::connect(
        pTrueWindow->getUI()->SpeedBox,
        QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this,
        &StateRun::SetSpeedModyfier
    );
}

StateRun::~StateRun()
{
    delete BuzyUpdateTimer;
}

void StateRun::Enter()
{
    Ui::MainWindow* ui = static_cast<MainWindow*>(PWindow)->getUI();

    // Программа
    ui->action_CreateNewField->setEnabled(false);
    ui->action_CloseField->setEnabled(false);
    ui->action_SaveFieldAs->setEnabled(false);
    ui->action_LoadField->setEnabled(false);

    // Поле
    ui->menu_Field->setEnabled(false);
    //ui->action_ClearField->setEnabled(false);

    // Симуляция
    ui->action_OneStep->setEnabled(false);
    ui->action_RunStop->setEnabled(true);

    // Прочие кнопки
    ui->pbStep->setEnabled(false);
    ui->pbRun->setEnabled(false);
    ui->pbStop->setEnabled(true);

    // Иконки
    QIcon iconState;
    iconState = QIcon(":/img/icons/stop");
    ui->action_RunStop->setIcon(iconState);
    ui->action_RunStop->setText("Остановить");

    BuzyUpdateTimer->start();
    static_cast<MainWindow*>(PWindow)->setCanChangeCell(false);
}

void StateRun::Exit()
{
    Ui::MainWindow* ui = static_cast<MainWindow*>(PWindow)->getUI();

    ui->menu_Field->setEnabled(true);

    BuzyUpdateTimer->stop();
}

bool StateRun::isRunning() const {
    return true;
}

void StateRun::SetSpeedModyfier(double val)
{
    BuzyUpdateTimer->setInterval(int(round(BASE_TIMER_INTERVAL / val)));
}

}
