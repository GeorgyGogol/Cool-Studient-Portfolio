//---------------------------------------------------------------------------

#ifndef uMainFormH
#define uMainFormH

#include "Calcer.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ActnMan.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <PlatformDefaultStyleActnCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *mmMain;
	TActionManager *amMain;
	TGridPanel *GridPanel1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TAction *aShowSettingsForm;
	TAction *aReset;
	TMenuItem *N1;
	TAction *aMore;
	TAction *aLess;
	TAction *aReady;
	TStatusBar *sbMain;
	TLabel *MainLabel;
	TLabel *LabelNumber;
	TAction *aStart;
	TMenuItem *aStart1;
	TMenuItem *N3;
	TAction *aAutoSearch;
	TMenuItem *N2;
	TMenuItem *N4;
	TMenuItem *N5;
	TAction *aShowCalcAgeForm;
	TMenuItem *N6;
	void __fastcall aShowSettingsFormExecute(TObject *Sender);
	void __fastcall aStartExecute(TObject *Sender);
	void __fastcall aLessExecute(TObject *Sender);
	void __fastcall aMoreExecute(TObject *Sender);
	void __fastcall aResetExecute(TObject *Sender);
	void __fastcall aReadyExecute(TObject *Sender);
	void __fastcall aAutoSearchExecute(TObject *Sender);
	void __fastcall aShowCalcAgeFormExecute(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
	Calcer* Core;

	void SetIsRun(bool state);
	void TryLoadLastTry();

	void UpdatePanel();
	void UpdateCaption();

	void PanelSetMin(int val);
	void PanelSetMax(int val);
	void PanelSetStep(int val);
	void PanelSetAccuracy(int val);

public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
