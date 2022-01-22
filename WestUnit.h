//---------------------------------------------------------------------------

#ifndef WestUnitH
#define WestUnitH

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

class TWest_Form : public TForm
{
__published:	// IDE-managed Components

	//Игра "Дикий запад"
	TImage *BackGround;
	TLabel *West_Text1;
	TLabel *West_YourScore;
	TLabel *West_Text3;
	TLabel *Money;
	TLabel *West_Text4;
	TButton *West_NewGame;
	TButton *West_Cancel;
	TPanel *Panel;
	TImage *BackImage;
	TTimer *LevelTimer;
	TTimer *ScoreTimer;
	TTimer *EnemyTimer;
	TImage *Enemy;
	TImage *Player;
	TLabel *West_Level;
	TLabel *West_Text5;
	TLabel *BestScore;

	//Процедуры и функции
	void __fastcall FormShow(TObject *Sender);
	void __fastcall West_CancelClick(TObject *Sender);
	void __fastcall BackImageMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall West_NewGameClick(TObject *Sender);
	void __fastcall LevelTimerTimer(TObject *Sender);
	void __fastcall ScoreTimerTimer(TObject *Sender);
	void __fastcall EnemyTimerTimer(TObject *Sender);
	void __fastcall EndGame();

private:	// User declarations
public:		// User declarations

	__fastcall TWest_Form(TComponent* Owner);
};

//---------------------------------------------------------------------------

extern PACKAGE TWest_Form *West_Form;

//---------------------------------------------------------------------------

#endif
