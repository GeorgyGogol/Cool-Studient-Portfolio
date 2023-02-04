//---------------------------------------------------------------------------

#ifndef udAimAutoH
#define udAimAutoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TdAimAuto : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *eAim;
	TFlowPanel *FlowPanel1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
private:	// User declarations
public:		// User declarations
	__fastcall TdAimAuto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TdAimAuto *dAimAuto;
//---------------------------------------------------------------------------
#endif
