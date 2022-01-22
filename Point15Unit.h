//---------------------------------------------------------------------------

#ifndef Point15UnitH
#define Point15UnitH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>

#include "MainUnit.h"
#include <Vcl.Graphics.hpp>

//---------------------------------------------------------------------------

class TPoint15_Form : public TForm
{
__published:	// IDE-managed Components
	TImage *BackGround;
	TLabel *Point15_Text3;
	TLabel *Money;
	TLabel *Point15_Text4;
	TLabel *Point21_Text1;
	TLabel *Steps;
	TButton *Point15_NewGame;
	TButton *Point15_Cancel;
	TPanel *Panel;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	TImage *Image9;
	TImage *Image10;
	TImage *Image11;
	TImage *Image12;
	TImage *Image13;
	TImage *Image14;
	TImage *Image15;
	TImage *Image1;
	TImage *Image2;
	TLabel *Point15_Text5;
	TLabel *BestScore;

    //Процедуры и функции
	void __fastcall Point15_CancelClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Point15_NewGameClick(TObject *Sender);
	void __fastcall MyClick(TObject *Sender);
	void __fastcall RandomPos();
	void __fastcall	FindEmptyPos();
	void __fastcall EndGame();

private:	// User declarations
public:		// User declarations

	__fastcall TPoint15_Form(TComponent* Owner);
};

//---------------------------------------------------------------------------

extern PACKAGE TPoint15_Form *Point15_Form;

//---------------------------------------------------------------------------

#endif
