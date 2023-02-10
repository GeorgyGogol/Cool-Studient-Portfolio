#include "mainformstatusbar.h"

MainFormStatusBar::MainFormStatusBar(QWidget* parent) :
    QStatusBar(parent),
    worldAge(new QLabel(this)),
    aliveCount(new QLabel(this))
{
}

MainFormStatusBar::~MainFormStatusBar()
{
    delete worldAge;
    delete aliveCount;
}

void MainFormStatusBar::UpdateWorldAge(const unsigned int& age)
{
    worldAge->setText("Возраст мира: " + QString::number(age));
}

void MainFormStatusBar::UpdateAliveCount(const unsigned int& count)
{
    aliveCount->setText("Живых клеток: " + QString::number(count));
}

void MainFormStatusBar::Clear()
{
    worldAge->setText("Возраст мира не определен");
    aliveCount->setText("Живых клеток нет");
}

