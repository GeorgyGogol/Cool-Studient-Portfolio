//---------------------------------------------------------------------------

#ifndef uSettingsFormH
#define uSettingsFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TSettings : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TFlowPanel *FlowPanel1;
	TLabel *Label1;
	TEdit *eMinVal;
	TLabel *Label2;
	TEdit *eMaxVal;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TEdit *eAccuracy;
	TLabel *Label3;
private:	// User declarations
public:		// User declarations
	__fastcall TSettings(TComponent* Owner);

	int getMinValue() const;
	int getMaxValue() const;
	int getAccuaryRang() const;
	double getTargetAccuracy() const;

	__property int MinValue = { read = getMinValue };
	__property int MaxValue = { read = getMaxValue };
	__property double Accuracy = { read = getTargetAccuracy };

};
//---------------------------------------------------------------------------
extern PACKAGE TSettings *Settings;
//---------------------------------------------------------------------------
#endif
