//---------------------------------------------------------------------------

#include <vcl.h>
#include <cmath>
#pragma hdrstop

#include "uSettingsForm.h"
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
