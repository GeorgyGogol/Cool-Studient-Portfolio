#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "statemanager.h"
#include "automat/core.h"
#include "controlledgridscene.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //Q_PROPERTY(Ui::MainWindow* UI READ getUI)

private:
    states::StateManager* WindowStatus;
    automat::cField* Field;
    ControlledGridScene* mainScene;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void CreateGraphicField();
    void ClearGraphicField();

private slots:
    // Программа
    void on_action_CreateNewField_triggered();
    void on_action_CloseField_triggered();
    void on_action_SaveFieldAs_triggered();
    void on_action_LoadField_triggered();

    // Поле
    void on_action_AutofillField_triggered();
    void on_action_ClearField_triggered();

    // Симуляция
    void on_action_RunStop_triggered();

    // Справка
    void on_action_About_triggered();
    void on_action_Rules_triggered();

    // Прочие
    void on_ScaleBox_valueChanged(double arg1);


public slots:
    void UpdateTick();
    void StepTick();

    void UpdateMapSizeInfo();

private:
    Ui::MainWindow *ui;

public:
    Ui::MainWindow* getUI() const;
    void setCanChangeCell(bool state);

};

#endif // MAINWINDOW_H
