#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../watcher.h"
#include <QGraphicsScene>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    unsigned int nMousePos;
    WWatcher* MouseWatcher;
    QGraphicsScene* sceneObjects;
    bool isTracking;
    QLabel* lTrackingTextStatus;

private slots:
    void on_action_StartStop_triggered();
    void on_action_newWatcher_triggered();
    void on_action_Save_triggered();
    void on_action_Load_triggered();

public slots:
    void MouseClickAt(QMouseEvent* event);
    void MousePos(int X, int Y);
    void AddPointAt(QMouseEvent* event);

};

#endif // MAINWINDOW_H
