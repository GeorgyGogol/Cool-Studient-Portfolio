#include "statewithfield.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>

namespace states {

StateWithField::StateWithField(QMainWindow* pWindow) :
    WindowPointKeeper<QMainWindow>(pWindow),
    LazyUpdateTimer(new QTimer(PWindow))
{
    LazyUpdateTimer->setInterval(250);
    QObject::connect(LazyUpdateTimer, &QTimer::timeout, static_cast<MainWindow*>(PWindow), &MainWindow::UpdateTick);
}

StateWithField::~StateWithField()
{
    delete LazyUpdateTimer;
}

void StateWithField::Enter()
{
    Ui::MainWindow* ui = static_cast<MainWindow*>(PWindow)->getUI();

    // Программа
    ui->action_CreateNewField->setEnabled(true);
    ui->action_CloseField->setEnabled(true);
    ui->action_SaveFieldAs->setEnabled(true);
    ui->action_LoadField->setEnabled(true);

    // Поле
    ui->action_ClearField->setEnabled(true);

    // Симуляция
    ui->action_OneStep->setEnabled(true);
    ui->action_RunStop->setEnabled(true);

    // Прочие кнопки
    ui->pbStep->setEnabled(true);
    ui->pbRun->setEnabled(true);
    ui->pbStop->setEnabled(false);
    ui->SpeedBox->setEnabled(true);

    // Иконки
    QIcon iconState;
    iconState = QIcon(":/img/icons/play");
    ui->action_RunStop->setIcon(iconState);
    ui->action_RunStop->setText("Запустить");

    LazyUpdateTimer->start();
    static_cast<MainWindow*>(PWindow)->setCanChangeCell(true);

    static_cast<MainWindow*>(PWindow)->UpdateMapSizeInfo();
}

void StateWithField::Exit()
{
    LazyUpdateTimer->stop();
}

bool StateWithField::isRunning() const {
    return false;
}

}
