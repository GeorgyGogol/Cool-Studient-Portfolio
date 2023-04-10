#include "autofillsettingsform.h"
#include "ui_autofillsettingsform.h"

AutoFillSettingsForm::AutoFillSettingsForm(int width, int height, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutoFillSettingsForm)
{
    ui->setupUi(this);
}

AutoFillSettingsForm::~AutoFillSettingsForm()
{
    delete ui;
}

int AutoFillSettingsForm::getNedeedAliveCount() const noexcept
{
    int out = -1;
    if (ui->rbFillWithCount->isChecked())
        out = ui->spb_Count->value();
    return out;
}

int AutoFillSettingsForm::getNeededPercentCount() const noexcept
{
    int out = -1;
    if (ui->rbFillWithPercent->isChecked())
        out = ui->spb_Percent->value();
    return out;
}

void AutoFillSettingsForm::on_cbEnableAutoFill_stateChanged(int arg1)
{
    ui->label_MaxCount->setEnabled(arg1);
    ui->label_InRadius->setEnabled(arg1);
    ui->spb_InRadius->setEnabled(arg1);
    ui->label_MaxCountLabel->setEnabled(arg1);
    ui->rbFillWithCount->setEnabled(arg1);
    ui->spb_Count->setEnabled(arg1 && ui->rbFillWithCount->isChecked());
    ui->rbFillWithPercent->setEnabled(arg1);
    ui->spb_Percent->setEnabled(arg1 && ui->rbFillWithPercent->isChecked());
}

void AutoFillSettingsForm::on_spb_InRadius_valueChanged(int arg1)
{
    arg1 *= arg1;
    ui->label_MaxCountLabel->setText(QString::number(arg1));
    ui->spb_Count->setMaximum(arg1);
}

void AutoFillSettingsForm::on_rbFillWithPercent_toggled(bool checked)
{
    ui->spb_Percent->setEnabled(checked);
}

void AutoFillSettingsForm::on_rbFillWithCount_toggled(bool checked)
{
    ui->spb_Count->setEnabled(checked);
}
