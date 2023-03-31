//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uCalcAgeForm.h"

#include <Dateutils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCalcAge *CalcAge;
//---------------------------------------------------------------------------
__fastcall TCalcAge::TCalcAge(TComponent* Owner)
	: TForm(Owner)
{
	dtpInput->MaxDate = Now();
	lAges->Caption = "";
	lMonthes->Caption = "";
    lDays->Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TCalcAge::bbCalcClick(TObject *Sender)
{
	lAges->Caption = FloatToStrF(MonthsBetween(Now(), dtpInput->Date) / 12.0, ffGeneral, 5, 3);
	lMonthes->Caption = IntToStr(MonthsBetween(Now(), dtpInput->Date));
	lDays->Caption = IntToStr(DaysBetween(Now(), dtpInput->Date));
}
//---------------------------------------------------------------------------

