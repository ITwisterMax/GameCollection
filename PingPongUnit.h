//---------------------------------------------------------------------------

#ifndef PingPongUnitH
#define PingPongUnitH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>

#include "MainUnit.h"

//---------------------------------------------------------------------------

class TPingPong_Form : public TForm
{
__published:	// IDE-managed Components

	//Игра "Пинг-понг"
	TImage *BackGround;
	TLabel *PingPong_Text1;
	TLabel *YourScore;
	TLabel *PingPong_Text3;
	TLabel *Money;
	TLabel *PingPong_Text4;
	TLabel *PingPong_Text2;
	TLabel *ComputerScore;
	TButton *PingPong_NewGame;
	TButton *PingPong_Cancel;
	TPanel *Panel;
	TImage *Image;
	TShape *BoardL;
	TShape *BoardR;
	TShape *Ball;
	TTimer *Timer1;
	TTimer *Timer2;

	//Процедуры и функции
	void __fastcall PingPong_CancelClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Restart();
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall PingPong_NewGameClick(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);

private:	// User declarations
public:		// User declarations

	__fastcall TPingPong_Form(TComponent* Owner);
};

//---------------------------------------------------------------------------

extern PACKAGE TPingPong_Form *PingPong_Form;

//---------------------------------------------------------------------------

#endif
