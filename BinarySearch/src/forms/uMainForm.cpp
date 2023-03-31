//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uMainForm.h"
#include "uSettingsForm.h"
#include "uCalcAgeForm.h"
#include "udAimAuto.h"

#include "SettingsFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	TryLoadLastTry();
    LabelNumber->Caption = "Приложение загружено...";

#ifdef _DEBUG
	Caption = Caption + " (Debug)";
#endif
}
//---------------------------------------------------------------------------
void TMainForm::SetIsRun(bool state)
{
	aStart->Enabled = !state;
	aShowSettingsForm->Enabled = !state;
	aMore->Enabled = state;
	aLess->Enabled = state;
	aReady->Enabled = state;
}
//---------------------------------------------------------------------------
void TMainForm::TryLoadLastTry()
{
	int min = 0, max = 100;

	if (FileExists(SETTINGS)) {
		TIniFile* file = new TIniFile(SETTINGS);

		// Подтянем последнее
		min = file->ReadInteger("Last", "Min", 0);
		max = file->ReadInteger("Last", "Max", 100);

		// Если есть дефолт - переопределим последнее
		min = file->ReadInteger("Default", "Min", min);
		max = file->ReadInteger("Default", "Max", max);

		delete file;
	}

	Core = new Calcer(min, max);
	UpdatePanel();
}
//---------------------------------------------------------------------------
void TMainForm::UpdatePanel()
{
	PanelSetMax(Core->Max);
	PanelSetMin(Core->Min);
	PanelSetStep(Core->StepCount);
}
//---------------------------------------------------------------------------
void TMainForm::UpdateCaption()
{
	String text = "Текущее число: ";

	text += FloatToStr(Core->getCurrentNumber());

	text += " - Больше, меньше или угадал?";
	LabelNumber->Caption = text;
	PanelSetStep(Core->StepCount);
}
//---------------------------------------------------------------------------
void TMainForm::PanelSetMin(int val)
{
	sbMain->Panels->Items[1]->Text = "Мин: " + IntToStr(val);
}
//---------------------------------------------------------------------------
void TMainForm::PanelSetMax(int val)
{
	sbMain->Panels->Items[2]->Text = "Макс: " + IntToStr(val);
}
//---------------------------------------------------------------------------
void TMainForm::PanelSetStep(int val)
{
	sbMain->Panels->Items[3]->Text = "Текущая итерация: " + IntToStr(val);
}
//---------------------------------------------------------------------------
void TMainForm::PanelSetAccuracy(int val)
{
	sbMain->Panels->Items[0]->Text = "Погрешность: 10^" + IntToStr(val);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aShowSettingsFormExecute(TObject *Sender)
{
	int min = Core->Min, max = Core->Max;

	Settings->MinValue = min;
	Settings->MaxValue = max;
	Settings->ShowModal();

	try
	{
		Core->Min = Settings->MinValue;
		Core->Max = Settings->MaxValue;
	}
	catch(Exception& e) {
		Application->ShowException(&e);
		Core->Min = min;
		Core->Max = max;
	}
	UpdatePanel();
	PanelSetAccuracy(Settings->getAccuaryRang());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aStartExecute(TObject *Sender)
{
	SetIsRun(true);
	Core->Start();
	UpdateCaption();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aLessExecute(TObject *Sender)
{
	Core->Less();
	UpdateCaption();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aMoreExecute(TObject *Sender)
{
	Core->More();
	UpdateCaption();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::aResetExecute(TObject *Sender)
{
	SetIsRun(false);
	Core->Reset();
    UpdatePanel();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aReadyExecute(TObject *Sender)
{
	Core->Stop();
	SetIsRun(false);

	String message = "Число ";
	message += FloatToStr(Core->getCurrentNumber());
	message += " было угадано за ";
	message += IntToStr(Core->StepCount);
	message += " итераций";

	LabelNumber->Caption = message;
	ShowMessage(message);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aAutoSearchExecute(TObject *Sender)
{
	dAimAuto = new TdAimAuto(this);
	while (dAimAuto->ShowModal()){
		if (dAimAuto->ModalResult == mrCancel) return;

		if (dAimAuto->ModalResult == mrOk) break;
	}

	double aim = dAimAuto->eAim->Text.ToDouble();

    aStart->Execute();

	Core->Calc(aim, 1.0 / Settings->Accuracy);

	aReady->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::aShowCalcAgeFormExecute(TObject *Sender)
{
    CalcAge->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	TIniFile* file = new TIniFile(SETTINGS);
	file->WriteInteger("Last", "Min", Core->Min);
	file->WriteInteger("Last", "Max", Core->Max);
	delete file;
	delete Core;
}
//---------------------------------------------------------------------------

