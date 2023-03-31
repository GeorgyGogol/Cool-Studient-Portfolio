//---------------------------------------------------------------------------

#ifndef uCalcAgeFormH
#define uCalcAgeFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCalcAge : public TForm
{
__published:	// IDE-managed Components
	TDateTimePicker *dtpInput;
	TLabel *Label1;
	TBitBtn *bbReturn;
	TBitBtn *bbCalc;
	TGridPanel *gpClient;
	TFlowPanel *fpBottomControl;
	TLabel *Label2;
	TLabel *lAges;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *lMonthes;
	TLabel *Label7;
	TLabel *lDays;
	void __fastcall bbCalcClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCalcAge(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCalcAge *CalcAge;
//---------------------------------------------------------------------------
#endif
