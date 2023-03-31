//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "uSettingsForm.h"
#include "SettingsFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSettings *Settings;
//---------------------------------------------------------------------------
__fastcall TSettings::TSettings(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TSettings::setMinValue(int value)
{
	eMinVal->Text = IntToStr(value);
}
//---------------------------------------------------------------------------
void TSettings::setMaxValue(int value)
{
	eMaxVal->Text = IntToStr(value);
}
//---------------------------------------------------------------------------
int TSettings::getMaxValue() const
{
	return eMaxVal->Text.ToInt();
}
//---------------------------------------------------------------------------
int TSettings::getMinValue() const
{
	return eMinVal->Text.ToInt();
}
//---------------------------------------------------------------------------
int TSettings::getAccuaryRang() const
{
	return eAccuracy->Text.ToInt();
}
//---------------------------------------------------------------------------
double TSettings::getTargetAccuracy() const
{
	return std::pow10(eAccuracy->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TSettings::bbSetDefaultClick(TObject *Sender)
{
	TIniFile* file = new TIniFile(SETTINGS);
	file->WriteInteger("Default", "Min", MinValue);
	file->WriteInteger("Default", "Max", MaxValue);
	delete file;

    ShowMessage("Установленные настройки были сохранены!");
}
//---------------------------------------------------------------------------

