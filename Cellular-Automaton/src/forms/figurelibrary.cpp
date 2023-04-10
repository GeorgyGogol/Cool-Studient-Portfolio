#include "figurelibrary.h"
#include "ui_figurelibrary.h"

figureLibrary::figureLibrary(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::figureLibrary)
{
    ui->setupUi(this);
}

figureLibrary::~figureLibrary()
{
    delete ui;
}
