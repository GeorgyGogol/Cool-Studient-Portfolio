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
	TBitBtn *bbSetDefault;
	void __fastcall bbSetDefaultClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSettings(TComponent* Owner);

	void setMinValue(int value);
	void setMaxValue(int value);

	int getMinValue() const;
	int getMaxValue() const;
	int getAccuaryRang() const;
	double getTargetAccuracy() const;

	__property int MinValue = { read = getMinValue, write = setMinValue };
	__property int MaxValue = { read = getMaxValue, write = setMaxValue };
	__property double Accuracy = { read = getTargetAccuracy };

};
//---------------------------------------------------------------------------
extern PACKAGE TSettings *Settings;
//---------------------------------------------------------------------------
#endif
