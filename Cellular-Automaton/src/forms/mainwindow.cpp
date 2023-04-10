#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "fieldsettingsform.h"

#include <memory>
#include <QDateTime>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTextCodec>

#include "widgets/gcell.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    WindowStatus(new states::StateManager(this)),
    Field(nullptr),
    mainScene(new ControlledGridScene(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_OneStep, &QAction::triggered, this, &MainWindow::StepTick);
    connect(ui->action_CloseField, &QAction::triggered, ui->sbMain, &MainFormStatusBar::Clear);

    //mainScene->CreateFieldView(ui->gv_Field);
    ui->gv_Field->setScene(mainScene);

    ui->gv_Minimap->setScene(mainScene);

    WindowStatus->SetStateEmpty();

    ui->pb_ShowMinimap->hide();
}

MainWindow::~MainWindow()
{
    delete WindowStatus;

    delete ui;
    delete mainScene;

    if(Field) delete Field;
}

void MainWindow::CreateGraphicField()
{
    if (!Field) return;

    mainScene->setSceneRect(0, 0, 50 * Field->getWidth(), 50 * Field->getHeight());
    for (auto y = 0; y < Field->getHeight(); ++y){
        for (auto x = 0; x < Field->getWidth(); ++x) {
            mainScene->createCellAt(x, y, Field->getCell(x, y));
        }
    }

    qreal sx = 1.0, sy = 1.0;
    sx = 1.0 * ui->gv_Minimap->width() / mainScene->width();
    sy = 1.0 * ui->gv_Minimap->height() / mainScene->height();
    ui->gv_Minimap->resetTransform();
    ui->gv_Minimap->scale(sx, sy);
}

void MainWindow::ClearGraphicField()
{
    mainScene->clear();
    mainScene->clearFocus();
    mainScene->update();
    mainScene->setSceneRect(0, 0, 0, 0);
}

void MainWindow::on_action_CreateNewField_triggered()
{
    if(Field && 
        QMessageBox::question(
            this,
            "Внимание!",
            "Поле уже существует!\nВы действительно хотите создать новое?",
            QMessageBox::Ok | QMessageBox::Cancel
        ) == QMessageBox::Cancel
    )
    {
        return;
    }

    std::unique_ptr<FieldSettingsForm> window (new FieldSettingsForm(this));

    if (window->exec() == QDialog::Accepted) {
        automat::FieldSettings fs;
        fs.Width = static_cast<unsigned int>(window->getWidth());
        fs.Height = static_cast<unsigned int>(window->getHeight());
        fs.FieldName = window->getName().toStdString();
        fs.CloseTopBottom = window->getTopBottomClose();
        fs.CloseLeftRight = window->getLeftRightClose();

        if (Field) {
            ClearGraphicField();
            delete Field;
        }
        Field = new automat::cField(fs);

        switch (window->isNeedAutofill()) {
        case 2:
            // TODO: Настройка и
            // fillRandom(Field, Settings);
            break;

        case 1:
            Field->FillRandome();
            break;

        default: /* 0 -> default */
            break;

        }

        WindowStatus->SetStateWithField();
        CreateGraphicField();
    }
}

void MainWindow::on_action_CloseField_triggered()
{
    ClearGraphicField();
    delete Field;
    Field = nullptr;

    WindowStatus->SetStateEmpty();
    ui->sbMain->Clear();
}

void MainWindow::on_action_SaveFieldAs_triggered()
{
	QTextCodec* codec = QTextCodec::codecForName("Windows-1251");

    QString fPath =
            QFileDialog::getSaveFileName(
                this,
                "Сохранить поле как...",
                QDir::currentPath(),
                "Field Files (*.txt);;All files (*.txt)"
                );

    if (fPath.length() < 1) return;

	QByteArray correctPath = codec->fromUnicode(fPath.toUtf8());

    automat::cFileServer server;
    server.SaveTo(Field, correctPath.toStdString().c_str());
}

void MainWindow::on_action_LoadField_triggered()
{
	QTextCodec* codec = QTextCodec::codecForName("Windows-1251");

    QString fPath =
            QFileDialog::getOpenFileName(
                this,
                "Открыть поле...",
                QDir::currentPath(),
                "Field Files (*.txt);;All files (*.txt)"
                );

    if (fPath.length() < 1) return;

	QByteArray correctPath = codec->fromUnicode(fPath.toUtf8());

    automat::cFileServer server;
    try {
        Field = server.LoadFrom(correctPath.toStdString().c_str());
        CreateGraphicField();
        WindowStatus->SetStateWithField();
    }
    catch (char* message) {
        QMessageBox::critical(this, "Ошибка загрузки!", QString(message));
        try {
            delete Field;
        } catch (...) {}
        Field = nullptr;
        WindowStatus->SetStateEmpty();
    }
}

void MainWindow::on_action_AutofillField_triggered()
{

}

void MainWindow::on_action_ClearField_triggered()
{
    Field->Clear();
}

void MainWindow::on_action_RunStop_triggered()
{
    if (!WindowStatus->isRunning())
        WindowStatus->SetStateIsRunning();
    else
        WindowStatus->SetStateWithField();
}

void MainWindow::on_action_About_triggered()
{
    QFile resAbout(":/txt/About");
    resAbout.open(QIODevice::ReadOnly);
    QTextStream load(&resAbout);
    load.setCodec(QTextCodec::codecForName("UTF-8"));
    QString sAbout = load.readAll();

    QMessageBox about(this);
    about.setWindowTitle(windowTitle());
    about.setIconPixmap(QPixmap(":/img/icons/main_icon"));
    about.setText("Простейший клеточный автомат");
    about.setInformativeText(sAbout);
    about.exec();
}

void MainWindow::on_action_Rules_triggered()
{    
    QFile resAbout(":/txt/Rules");
    resAbout.open(QIODevice::ReadOnly);
    QTextStream load(&resAbout);
    load.setCodec(QTextCodec::codecForName("UTF-8"));
    QString sAbout = load.readAll();

    QMessageBox::about(this, "Правила", sAbout);
}

void MainWindow::on_ScaleBox_valueChanged(double arg1)
{
    ui->gv_Field->resetTransform();
    ui->gv_Field->scale(arg1, arg1);
}

void MainWindow::UpdateTick()
{
    mainScene->update();

    ui->sbMain->UpdateAliveCount(Field->getAliveCount());
    ui->sbMain->UpdateWorldAge(Field->getAge());
}

void MainWindow::StepTick()
{
    if (!Field->step()) {
        WindowStatus->SetState<states::StateGameOver>();
        WindowStatus->SetStateWithField();
    }
}

void MainWindow::UpdateMapSizeInfo()
{
    if (Field) {
        ui->sbMain->UpdateMapSize(Field->getWidth(), Field->getHeight());
        ui->gbMapInformation->UpdateInfo(Field);
    }
    else {
        ui->gbMapInformation->ResetInfo();
    }

}

Ui::MainWindow* MainWindow::getUI() const
{
    return ui;
}

void MainWindow::setCanChangeCell(bool state)
{
    mainScene->canChange = state;
}
