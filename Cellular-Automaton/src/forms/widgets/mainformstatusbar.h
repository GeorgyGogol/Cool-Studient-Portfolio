#ifndef MAINFORMSTATUSBAR_H
#define MAINFORMSTATUSBAR_H

#include <QStatusBar>
#include <QLabel>

class MainFormStatusBar : public QStatusBar
{
public:
    MainFormStatusBar(QWidget* parent = nullptr);
    ~MainFormStatusBar();

private:
    QLabel* worldAge;
    QLabel* aliveCount;
    QLabel* MapSize;

public slots:
    void UpdateWorldAge(unsigned int age);
    void UpdateAliveCount(unsigned int count);
    void UpdateMapSize(int width, int height);

    void Clear();

};

#endif // MAINFORMSTATUSBAR_H
