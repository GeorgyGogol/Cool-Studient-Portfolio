#include "mainformstatusbar.h"

MainFormStatusBar::MainFormStatusBar(QWidget* parent) :
    QStatusBar(parent),
    worldAge(new QLabel(this)),
    aliveCount(new QLabel(this)),
    MapSize(new QLabel(this))
{
    Clear();

    addWidget(worldAge);
    addWidget(aliveCount);
    addWidget(MapSize);
}

MainFormStatusBar::~MainFormStatusBar()
{
    delete worldAge;
    delete aliveCount;
    delete MapSize;
}

void MainFormStatusBar::UpdateWorldAge(unsigned int age)
{
    worldAge->setText("Возраст мира: " + QString::number(age));
}

void MainFormStatusBar::UpdateAliveCount(unsigned int count)
{
    aliveCount->setText("Живых клеток: " + QString::number(count));
}

void MainFormStatusBar::UpdateMapSize(int width, int height)
{
    MapSize->setText("Размер: " + QString::number(long(width) * long(height)));
}

void MainFormStatusBar::Clear()
{
    worldAge->setText("Возраст мира не определен");
    aliveCount->setText("Живых клеток нет");
    MapSize->setText("Размер не определен");
}

