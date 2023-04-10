#include "fieldinfobox.h"
#include "ui_fieldinfobox.h"

FieldInfoBox::FieldInfoBox(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FieldInfoBox)
{
    ui->setupUi(this);
    ResetInfo();
}

FieldInfoBox::~FieldInfoBox()
{
    delete ui;
}

void FieldInfoBox::UpdateInfo(const automat::cField* field)
{
    int width = field->getWidth();
    int height = field->getHeight();

    ui->label_Name->setText(field->getFieldName());
    ui->label_Width->setText(QString::number(width));
    ui->label_Height->setText(QString::number(height));
    ui->label_CellsTotal->setText(QString::number(long(width) * height));
}

void FieldInfoBox::ResetInfo()
{
    ui->label_Name->setText("Поле не загружено");
    ui->label_Width->setText(QString::number(0));
    ui->label_Height->setText(QString::number(0));
    ui->label_CellsTotal->setText(QString::number(0));
}
