//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ActnMenus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TShape *Shape2;
	TShape *Shape3;
	TShape *Shape4;
	TShape *Shape5;
	TShape *Shape7;
	TShape *Shape9;
	TShape *Shape10;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TMenuItem *Help1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	TMenuItem *About1;
	TMenuItem *Rules1;
	TMenuItem *New;
	TButton *Lock;
	TMenuItem *N1;
	TMenuItem *mnuEasy;
	TMenuItem *mnuMiddle;
	TMenuItem *mnuHard;
	TButton *Button1;
    void __fastcall ColourSet();
	void __fastcall Rules1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall NewClick(TObject *Sender);
	void __fastcall LockClick(TObject *Sender);
	void __fastcall LvlEasy(TObject *Sender);
	void __fastcall LvlMiddle(TObject *Sender);
	void __fastcall LvlHard(TObject *Sender);
	void __fastcall CheckValues(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
