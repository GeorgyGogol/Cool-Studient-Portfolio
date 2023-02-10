#ifndef MAINFORMSTATUSBAR_H
#define MAINFORMSTATUSBAR_H


#include <QStatusBar>
#include <QLabel>
//#include "../../automat/core.h"

class MainFormStatusBar : public QStatusBar
{
public:
    MainFormStatusBar(QWidget* parent = nullptr);
    ~MainFormStatusBar();

private:
    QLabel* worldAge;
    QLabel *aliveCount;

public slots:
    //void updateInformation(const automat::cField* field);
    void UpdateWorldAge(const unsigned int& age);
    void UpdateAliveCount(const unsigned int& count);

    void Clear();

};

#endif // MAINFORMSTATUSBAR_H
