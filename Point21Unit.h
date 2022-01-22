//---------------------------------------------------------------------------

#ifndef Point21UnitH
#define Point21UnitH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>

#include "MainUnit.h"

//---------------------------------------------------------------------------

class TPoint21_Form : public TForm
{
__published:	// IDE-managed Components

	//Игра "21 очко"
	TLabel *Point21_Text3;
	TLabel *Point21_Text1;
	TLabel *Point21_YourScore;
	TLabel *Point21_Text2;
	TLabel *Point21_ComputerScore;
	TButton *Point21_More;
	TButton *Point21_NewGame;
	TButton *Point21_Stop;
	TButton *Point21_Cancel;
	TLabel *Money;
	TLabel *Point21_Text4;
	TImage *Point21_Image1;
	TImage *Point21_Image2;
	TImage *Point21_Image3;
	TImage *Point21_Image4;
	TImage *Point21_Image5;
	TImage *Point21_Image6;
	TImage *Point21_Image7;
	TImage *Point21_Image8;
	TImage *Point21_Image9;
	TImage *Point21_Image10;
	TImage *BackGround;
	TImage *Point21_Image11;
	TImage *Point21_Image12;
	TImage *Point21_Image13;
	TImage *Point21_Image14;
	TImage *Point21_Image15;
	TImage *Point21_Image16;
	TImage *Point21_Image18;
	TImage *Point21_Image17;

	//Процедуры и функции
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Point21_EndGame();
	void __fastcall Point21_ResetImages();
	void __fastcall Point21_GetP();
	void __fastcall Point21_Get();
	void __fastcall Point21_MoreClick(TObject *Sender);
	void __fastcall Point21_StopClick(TObject *Sender);
	void __fastcall Point21_NewGameClick(TObject *Sender);
	void __fastcall Point21_CancelClick(TObject *Sender);

private:	// User declarations
public:		// User declarations

	__fastcall TPoint21_Form(TComponent* Owner);
};

//---------------------------------------------------------------------------

extern PACKAGE TPoint21_Form *Point21_Form;

//---------------------------------------------------------------------------

#endif
