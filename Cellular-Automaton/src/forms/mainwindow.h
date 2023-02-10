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

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void CreateField(const automat::FieldSettings& fs);
    void DeleteField();
    void LoadField(QString path);
    void UpdateGUIState();
    bool doStep();

private slots:
    void TimerTickSlot();

    void on_action_CreateNewField_triggered();
    void on_action_CloseField_triggered();
    void on_action_SaveAs_triggered();
    void on_action_Load_triggered();
    void on_action_OneStep_triggered();
    void on_action_RunStop_triggered();
    void on_action_About_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
