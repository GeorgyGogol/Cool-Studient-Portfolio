#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "fieldsettingsform.h"

#include <memory>
#include <QDateTime>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTextCodec>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Field(nullptr),
    isRun(false), delay(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(mainScene);

    Timer = new QTimer(this);
    connect(Timer, &QTimer::timeout, this, &MainWindow::TimerTickSlot);
    Timer->setInterval(1000 / 10);

    UpdateGUIState();
}

MainWindow::~MainWindow()
{
    delete ui;
    DeleteField();
    delete mainScene;
}

void MainWindow::CreateField(const automat::FieldSettings& fs)
{
    if (Field) return;

    Field = new automat::cField(fs);

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

    Timer->start();
}

void MainWindow::DeleteField()
{
    if (!Field) return;

    mainScene->clear();
    Timer->stop();
    delete Field;
    Field = nullptr;
}

void MainWindow::LoadField(QString path)
{
    if (Field) return;

    automat::cFileServer server;

    try {
        Field = server.LoadFrom(path.toStdString().c_str());
    } catch (...) {
        return;
    }


    mainScene->clear();
    mainScene->update();

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

    Timer->start();
}

void MainWindow::UpdateGUIState()
{
    bool state = Field;

    ui->action_CreateNewField->setEnabled(!state);
    ui->action_CloseField->setEnabled(state);
    ui->action_SaveAs->setEnabled(state);
    ui->action_CloseField->setEnabled(state);

    ui->action_OneStep->setEnabled(state && !isRun);
    ui->action_RunStop->setEnabled(state);

    if (state){
        QIcon iconState;
        QString textState;
        if (isRun){
            iconState = QIcon(":/img/icons/stop");
            textState = "Остановить";
        }
        else {
            iconState = QIcon(":/img/icons/play");
            textState = "Запустить";
        }
        ui->action_RunStop->setIcon(iconState);
        ui->action_RunStop->setText(textState);
        ui->pbRun->setIcon(iconState);
        ui->pbRun->setText(textState);
    }
}

bool MainWindow::doStep()
{
    return Field->step();
}

void MainWindow::TimerTickSlot()
{
    mainScene->update();

    if (isRun){
        if (delay >= 5) {
            isRun = doStep();
            if (!isRun) UpdateGUIState();
            delay = 0;
        }
        ++delay;
    }

    //updateStatusInformation();
}

void MainWindow::on_action_CreateNewField_triggered()
{
    std::unique_ptr<FieldSettingsForm> window (new FieldSettingsForm(this));

    if (window->exec() == QDialog::Accepted) {
        automat::FieldSettings fs;
        fs.Width = static_cast<unsigned int>(window->getWidth());
        fs.Height = static_cast<unsigned int>(window->getHeight());
        fs.FieldName = window->getName().toStdString();
        fs.CloseTopBottom = window->getTopBottomClose();
        fs.CloseLeftRight = window->getLeftRightClose();

        CreateField(fs);
    }

    UpdateGUIState();
}

void MainWindow::on_action_CloseField_triggered()
{
    DeleteField();
    UpdateGUIState();
}

void MainWindow::on_action_SaveAs_triggered()
{
    QString fPath =
            QFileDialog::getSaveFileName(
                this,
                "Сохранить поле как...",
                QDir::currentPath(),
                "Field Files (*.txt);;All files (*.txt)"
                );

    if (fPath.length() < 1) return;

    automat::cFileServer server;
    server.SaveTo(Field, fPath.toStdString().c_str());
}

void MainWindow::on_action_Load_triggered()
{
    QString fPath =
            QFileDialog::getOpenFileName(
                this,
                "Сохранить поле как...",
                QDir::currentPath(),
                "Field Files (*.txt);;All files (*.txt)"
                );

    if (fPath.length() < 1) return;

    DeleteField();
    LoadField(fPath);
    UpdateGUIState();
}

void MainWindow::on_action_OneStep_triggered()
{
    doStep();
}

void MainWindow::on_action_RunStop_triggered()
{
    delay = 0;
    isRun = !isRun;
    UpdateGUIState();
}

void MainWindow::on_action_About_triggered()
{
    QFile resAbout(":/txt/About");
    resAbout.open(QIODevice::ReadOnly);
    QTextStream load(&resAbout);
    load.setCodec(QTextCodec::codecForName("UTF-8"));
    QString sAbout = load.readAll();

    QMessageBox::about(this, "Клеточный автомат", sAbout);
}

