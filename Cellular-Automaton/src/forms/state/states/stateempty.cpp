#include "stateempty.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace states {

StateEmpty::StateEmpty(QMainWindow* pWindow) :
    WindowPointKeeper<QMainWindow>(pWindow)
{
}

StateEmpty::~StateEmpty() 
{}

void StateEmpty::Enter()
{
    Ui::MainWindow* ui = static_cast<MainWindow*>(PWindow)->getUI();

    // Программа
    ui->action_CreateNewField->setEnabled(true);
    ui->action_CloseField->setEnabled(false);
    ui->action_SaveFieldAs->setEnabled(false);
    ui->action_LoadField->setEnabled(true);

    // Поле
    ui->menu_Field->setEnabled(false);

    // Симуляция
    ui->menu_Run->setEnabled(false);

    // Прочие кнопки
    ui->pbStep->setEnabled(false);
    ui->pbRun->setEnabled(false);
    ui->pbStop->setEnabled(false);
    ui->ScaleBox->setEnabled(false);
    ui->SpeedBox->setEnabled(false);

    // Иконки
    QIcon iconState;
    iconState = QIcon(":/img/icons/play");
    ui->action_RunStop->setIcon(iconState);
    ui->action_RunStop->setText("Запустить");

    // Настройка поля
    static_cast<MainWindow*>(PWindow)->setCanChangeCell(false);

    static_cast<MainWindow*>(PWindow)->UpdateMapSizeInfo();
}

void StateEmpty::Exit()
{
    Ui::MainWindow* ui = static_cast<MainWindow*>(PWindow)->getUI();

    ui->menu_Field->setEnabled(true);

    ui->menu_Run->setEnabled(true);

    ui->ScaleBox->setEnabled(true);
    ui->SpeedBox->setEnabled(true);
}

bool StateEmpty::isRunning() const {
    return false;
}

}

