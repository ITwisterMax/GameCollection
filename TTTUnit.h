//---------------------------------------------------------------------------

#ifndef TTTUnitH
#define TTTUnitH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>

#include "MainUnit.h"

//---------------------------------------------------------------------------

class TTTT_Form : public TForm
{
__published:	// IDE-managed Components

	//Игра "Крестики-нолики"
	TImage *BackGround;
	TLabel *TTT_Text1;
	TLabel *TTT_YourScore;
	TLabel *TTT_Text5;
	TLabel *TTT_ComputerScore;
	TLabel *TTT_Text3;
	TLabel *Money;
	TLabel *TTT_Text4;
	TButton *TTT_NewGame;
	TButton *TTT_Cancel;
	TButton *Button1;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *Panel8;
	TPanel *Panel9;

	//Процедуры и функции
	void __fastcall TTT_CancelClick(TObject *Sender);
	void __fastcall TTT_NewGameClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Panel1Click(TObject *Sender);
	void __fastcall Panel2Click(TObject *Sender);
	void __fastcall Panel3Click(TObject *Sender);
	void __fastcall Panel4Click(TObject *Sender);
	void __fastcall Panel5Click(TObject *Sender);
	void __fastcall Panel6Click(TObject *Sender);
	void __fastcall Panel7Click(TObject *Sender);
	void __fastcall Panel8Click(TObject *Sender);
	void __fastcall Panel9Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations

	__fastcall TTTT_Form(TComponent* Owner);
};

//---------------------------------------------------------------------------

extern PACKAGE TTTT_Form *TTT_Form;

//---------------------------------------------------------------------------

#endif
