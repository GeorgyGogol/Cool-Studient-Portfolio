#include "fieldsettingsform.h"
#include "ui_fieldsettingsform.h"

FieldSettingsForm::FieldSettingsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FieldSettingsForm)
{
    ui->setupUi(this);
    connect(ui->spinWidth, SIGNAL(valueChanged(int)), this, SLOT(AutoDesideAutofill()));
    connect(ui->spinHeight, SIGNAL(valueChanged(int)), this, SLOT(AutoDesideAutofill()));
    
    connect(ui->rb_NoAutoFill, &QRadioButton::clicked, this, &FieldSettingsForm::UserChangeAutofill);
    connect(ui->rb_SimpleAutofill, &QRadioButton::clicked, this, &FieldSettingsForm::UserChangeAutofill);
    connect(ui->rb_AutoFill, &QRadioButton::clicked, this, &FieldSettingsForm::UserChangeAutofill);
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

int FieldSettingsForm::isNeedAutofill() const noexcept
{
    int out = -1;

    out += ui->rb_NoAutoFill->isChecked();
    out += ui->rb_SimpleAutofill->isChecked() * 2;
    out += ui->rb_AutoFill->isChecked() * 3;

    /*
    if      (ui->rb_NoAutoFill->isChecked())
        out = 0;
    else if (ui->rb_SimpleAutofill->isChecked())
        out = 1;
    else if (ui->rb_AutoFill->isChecked())
        out = 2;
    */

    return out;
}

void FieldSettingsForm::UserChangeAutofill()
{
    disconnect(ui->spinWidth, SIGNAL(valueChanged(int)), this, SLOT(AutoDesideAutofill()));
    disconnect(ui->spinHeight, SIGNAL(valueChanged(int)), this, SLOT(AutoDesideAutofill()));

    disconnect(ui->rb_NoAutoFill, &QRadioButton::clicked, this, &FieldSettingsForm::UserChangeAutofill);
    disconnect(ui->rb_SimpleAutofill, &QRadioButton::clicked, this, &FieldSettingsForm::UserChangeAutofill);
    disconnect(ui->rb_AutoFill, &QRadioButton::clicked, this, &FieldSettingsForm::UserChangeAutofill);
}

void FieldSettingsForm::AutoDesideAutofill()
{
    if (getWidth() < 6 && getHeight() < 6)
        ui->rb_NoAutoFill->setChecked(true);
    else
        ui->rb_SimpleAutofill->setChecked(true);
}
