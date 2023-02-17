#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QMessageBox>
#include <cmath>
#include "widgets/mousepoint.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    nMousePos(0),
    MouseWatcher(new WWatcher()),
    sceneObjects(new QGraphicsScene(this)),
    isTracking(false)
{
    ui->setupUi(this);
    ui->graphicsView->setMouseTracking(true);
    connect(ui->graphicsView, SIGNAL(MouseClickedAt(QMouseEvent*)), this, SLOT(MouseClickAt(QMouseEvent*)));
    connect(ui->graphicsView, SIGNAL(MouseClickedAt(QMouseEvent*)), this, SLOT(AddPointAt(QMouseEvent*)));
    connect(ui->graphicsView, SIGNAL(MouseClickedAt(int, int)), ui->groupBox_info, SLOT(UpdateCurrentPos(int, int)));
    connect(ui->graphicsView, &GraphicsWatchArea::MouseNowAt, this, &MainWindow::MousePos);
    connect(ui->graphicsView, &GraphicsWatchArea::MouseNowAt, ui->groupBox_info, &GroupBoxInfo::UpdateCurrentPos);

    ui->graphicsView->setScene(sceneObjects);

    lTrackingTextStatus = new QLabel(ui->statusBar);
    ui->statusBar->addWidget(lTrackingTextStatus);
    lTrackingTextStatus->setText("Не отслеживается");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete MouseWatcher;
    delete sceneObjects;
}

void MainWindow::on_action_StartStop_triggered()
{
    isTracking = !isTracking;

    QString statusText = "Не отслеживается";
    QString actionText = "Начать";
    if (isTracking) {
        statusText = "Отслеживается";
        actionText = "Остановить";
    }

    lTrackingTextStatus->setText(statusText);
    ui->action_StartStop->setText(actionText);

    ui->action_newWatcher->setDisabled(isTracking);
    ui->action_Save->setDisabled(isTracking);
    ui->action_Load->setDisabled(isTracking);
}

void MainWindow::on_action_newWatcher_triggered()
{
    sceneObjects->clear();
    sceneObjects->update();

    delete MouseWatcher;
    MouseWatcher = new WWatcher();
}

void MainWindow::on_action_Save_triggered()
{
    QString savePath =
            QFileDialog::getSaveFileName(
                this,
                "Сохранить",
                QDir::currentPath(),
                "Text files (*.txt)");

    if (savePath.isEmpty()) return;

    WIOManager save;
    save.Save(MouseWatcher, savePath.toStdString().c_str());
}

void MainWindow::on_action_Load_triggered()
{
    QString loadPath =
            QFileDialog::getSaveFileName(
                this,
                "Открыть",
                QDir::currentPath(),
                "Text files (*.txt)");

    if (loadPath.isEmpty()) return;
    if (MouseWatcher){
        delete MouseWatcher;
        sceneObjects->clear();
    }

    WIOManager load;
    MouseWatcher = load.Load(loadPath.toStdString().c_str());

    for (auto p = MouseWatcher->First(); !MouseWatcher->isEnd(); p = MouseWatcher->Next()) {
        MousePoint mp;
        mp.setX(p->X);
        mp.setY(p->Y);
        mp.MouseButtion = p->Button;
        sceneObjects->addItem(&mp);
    }
    sceneObjects->update();
}

void MainWindow::MouseClickAt(QMouseEvent* event)
{
    if (!isTracking) return;
    MouseWatcher->AddPoint(WPoint(event->x(), event->y(), event->button()));
}

void MainWindow::MousePos(int X, int Y)
{
    if (!isTracking) return;

    ++nMousePos;

    if (nMousePos >= 50){
        WPoint current_pos(X, Y);
        WPoint *prev_pos = MouseWatcher->Last();

        if (prev_pos){
            ui->groupBox_info->UpdateDelta(prev_pos->getRangeTo(current_pos));
            QMouseEvent mpoi(QEvent::Type::MouseMove, QPointF(X, Y), Qt::MouseButton::NoButton, nullptr, nullptr);
            AddPointAt(&mpoi);
        }

        MouseWatcher->AddPoint(current_pos);

        nMousePos = 0;
    }

    sceneObjects->setSceneRect(0, 0, this->ui->graphicsView->width(), this->ui->graphicsView->height());
    sceneObjects->update();
}

void MainWindow::AddPointAt(QMouseEvent* event)
{
    if (!isTracking) return;

    MousePoint* mp = new MousePoint();
    mp->setX(event->x());
    mp->setY(event->y());
    mp->MouseButtion = event->button();

    sceneObjects->addItem(mp);
}
