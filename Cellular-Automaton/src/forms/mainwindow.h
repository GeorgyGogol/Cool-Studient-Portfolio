#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "../automat/core.h"
#include "widgets/gcell.h"
#include <QTimer>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTimer* Timer;
    QGraphicsScene* mainScene;
    automat::cField* Field;
    bool isRun;
    unsigned int delay;

    QLabel* worldAge, *aliveCount;

    void checkStatus();
    void updateStatusInformation();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void TimerTickSlot();
    void on_pbStep_clicked();
    void on_bpRun_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
