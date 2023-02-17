#include "groupboxinfo.h"
#include "ui_groupboxinfo.h"

#define TEXT_MASK_CURRENT_POSITION "Текущая позиция: (%i, %i)"
#define TEXT_MASK_DELTA "Перемещение: %1"

GroupBoxInfo::GroupBoxInfo(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::GroupBoxInfo)
{
    ui->setupUi(this);
    UpdateCurrentPos(-1, -1);
    UpdateDelta(0);
}

GroupBoxInfo::~GroupBoxInfo()
{
    delete ui;
}

void GroupBoxInfo::UpdateCurrentPos(int X, int Y)
{
    QString label;
    label.sprintf(TEXT_MASK_CURRENT_POSITION, X, Y);
    ui->CurrentPos->setText(label);
}

void GroupBoxInfo::UpdateDelta(int delta)
{
    QString label = QString(TEXT_MASK_DELTA).arg(QString::number(delta));
    ui->Delta->setText(label);
}
