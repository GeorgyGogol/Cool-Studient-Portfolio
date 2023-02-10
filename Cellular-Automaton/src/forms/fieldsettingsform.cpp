#include "fieldsettingsform.h"
#include "ui_fieldsettingsform.h"

FieldSettingsForm::FieldSettingsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FieldSettingsForm)
{
    ui->setupUi(this);
}

FieldSettingsForm::~FieldSettingsForm()
{
    delete ui;
}

int FieldSettingsForm::getHeight() const noexcept
{
    return ui->spinHeight->value();
}

int FieldSettingsForm::getWidth() const noexcept
{
    return ui->spinWidth->value();
}

QString FieldSettingsForm::getName() const noexcept
{
    return ui->eName->text();
}

bool FieldSettingsForm::getTopBottomClose() const noexcept
{
    return ui->cbTopBottom->checkState();
}

bool FieldSettingsForm::getLeftRightClose() const noexcept
{
    return ui->cbLeftRight->checkState();
}
