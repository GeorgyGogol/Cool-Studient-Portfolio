#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <memory>
#include <QDateTime>

//static someObject* so;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    isRun(false), delay(0),
    worldAge(new QLabel(this)),
    aliveCount(new QLabel(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->addWidget(worldAge, 0);
    ui->statusBar->addWidget(aliveCount, 1);

    Field = new automat::cField(32, 32);

    mainScene = new QGraphicsScene(this);
    GCell* cell;
    for (auto y = 0; y < Field->getHeight(); ++y){
        for (auto x = 0; x < Field->getWidth(); ++x) {
            cell = new GCell(Field->getCell(x, y));

            cell->setY(y * 50);
            cell->setX(x * 50);
            cell->setCanChangeState(true);

            mainScene->addItem(cell);
            cell = nullptr;
        }
    }
    ui->graphicsView->setScene(mainScene);

    Timer = new QTimer(this);
    connect(Timer, &QTimer::timeout, this, &MainWindow::TimerTickSlot);
    Timer->setInterval(1000 / 10);
    Timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainScene;

    std::string dateStamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm").toStdString() + ".txt";

    automat::cFileServer server;
    server.SaveTo(Field, dateStamp.c_str());

    delete Field;
}

void MainWindow::checkStatus()
{
    if (isRun) {
        ui->bpRun->setText("Остановить");
    }
    else {
        ui->bpRun->setText("Запустить");
    }

    ui->pbStep->setEnabled(!isRun);
}

void MainWindow::updateStatusInformation()
{
    worldAge->setText("Возраст мира: " + QString::number(Field->getAge()));
    aliveCount->setText("Живых клеток: " + QString::number(Field->getAliveCount()));
}

void MainWindow::TimerTickSlot()
{
    mainScene->update();

    if (isRun){
        if (delay >= 5) {
            isRun = Field->step();
            delay = 0;
            checkStatus();
        }
        ++delay;
    }

    updateStatusInformation();
}

void MainWindow::on_pbStep_clicked()
{
    if (Field->getAliveCount() > 0) Field->step();
    updateStatusInformation();
}

void MainWindow::on_bpRun_clicked()
{
    isRun = !isRun && (Field->getAliveCount() > 0);
    delay = 0;
    checkStatus();
}
