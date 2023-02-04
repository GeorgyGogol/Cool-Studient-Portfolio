//---------------------------------------------------------------------------

#include <vcl.h>
#include <cmath>
#pragma hdrstop

#include "uMainForm.h"
#include "uSettingsForm.h"
#include "udAimAuto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	Reset();
	PanelSetMax(100);
	PanelSetMin(0);
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
void TMainForm::Reset()
{
	CurrentNumber = 0;
	CurrentStep = 0;
	delta = 0;
	PanelSetStep(0);
    LabelNumber->Caption = "Только бинарным. Только.";
}
//---------------------------------------------------------------------------
void TMainForm::Start()
{
	delta = 1.0 * (Settings->MaxValue - Settings->MinValue) / 2.0;
	CurrentNumber = Settings->MinValue + delta;
	CurrentStep = 1;

	UpdateCaption();
}
//---------------------------------------------------------------------------
void TMainForm::UpdateCaption()
{
	String text = "Текущее число: ";

	text += FloatToStr( (int)(1.0 * CurrentNumber * Settings->Accuracy) / (1.0 * Settings->Accuracy) );

	text += " - Больше, меньше или угадал?";
	LabelNumber->Caption = text;
	PanelSetStep(CurrentStep);
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
	Settings->ShowModal();
	PanelSetMin(Settings->MinValue);
	PanelSetMax(Settings->MaxValue);
	PanelSetAccuracy(Settings->getAccuaryRang());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aStartExecute(TObject *Sender)
{
	SetIsRun(true);
	Start();
	UpdateCaption();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aLessExecute(TObject *Sender)
{
	CurrentNumber -= delta / 2;
	delta /= 2;
	++CurrentStep;

	UpdateCaption();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aMoreExecute(TObject *Sender)
{
	CurrentNumber += delta / 2;
	delta /= 2;
	++CurrentStep;

	UpdateCaption();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::aResetExecute(TObject *Sender)
{
	SetIsRun(false);
    Reset();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::aReadyExecute(TObject *Sender)
{
	double number = int(CurrentNumber * Settings->Accuracy) / Settings->Accuracy;

	String message = "Число ";
	message += FloatToStr(number);
	message += " было угадано за ";
	message += IntToStr(int(CurrentStep));
	message += " итераций";

	LabelNumber->Caption = message;
	ShowMessage(message);

	SetIsRun(false);
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

	while ( std::fabs(aim - CurrentNumber) > (1 / Settings->Accuracy) ){

		if (CurrentNumber > aim) {
			aLess->Execute();
		}
		else {
			aMore->Execute();
		}
	};

	aReady->Execute();
}
//---------------------------------------------------------------------------

