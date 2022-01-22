//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.MPlayer.hpp>

#include "AccountUnit.h"
#include "PingPongUnit.h"
#include "Point21Unit.h"
#include "TTTUnit.h"
#include "Point15Unit.h"
#include "WestUnit.h"

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components

	TPageControl *Pages;
	TTabSheet *Menu;
	TTabSheet *LoadGame;

	//Меню
	TImage *BackGround1;
	TButton *LogIn;
	TButton *Play;
	TButton *Music;
	TButton *GameExit;
	TImage *Man;
	TLabel *NameText1;
	TLabel *Player1;
	TLabel *MoneyText1;
	TLabel *Money1;
	TLabel *TempText1;
	TLabel *HeadText1;
	TLabel *Temp;
	TMediaPlayer *MusicPlayer;

	//Выбор игры
	TImage *BackGround2;
	TLabel *NameText2;
	TLabel *Player2;
	TLabel *MoneyText2;
	TLabel *Money2;
	TLabel *TempText2;
	TPanel *P1;
	TImage *PingPongImage;
	TPanel *P2;
	TImage *Point21Image;
	TPanel *P3;
	TImage *TTTImage;
	TPanel *P4;
	TImage *Point15;
	TPanel *P5;
	TImage *WestImage;
	TLabel *HeadText2;
	TButton *Reset;
	TButton *GoToMenu;
	TImage *IsOpen1;
	TImage *IsOpen2;
	TImage *IsOpen3;
	TImage *IsOpen4;
	TImage *IsOpen5;

    //Процедуры и функции
	void __fastcall FormShow(TObject *Sender);
	void __fastcall LogInClick(TObject *Sender);
	void __fastcall PlayClick(TObject *Sender);
	void __fastcall MusicClick(TObject *Sender);
	void __fastcall MusicPlayerNotify(TObject *Sender);
	void __fastcall GameExitClick(TObject *Sender);
	void __fastcall LoadGameShow(TObject *Sender);
	void __fastcall ResetClick(TObject *Sender);
	void __fastcall GoToMenuClick(TObject *Sender);
	void __fastcall PingPongImageClick(TObject *Sender);
	void __fastcall Point21ImageClick(TObject *Sender);
	void __fastcall TTTImageClick(TObject *Sender);
	void __fastcall Point15Click(TObject *Sender);
	void __fastcall WestImageClick(TObject *Sender);

private:	// User declarations
public:		// User declarations

	__fastcall TMainForm(TComponent* Owner);
};

//---------------------------------------------------------------------------

extern PACKAGE TMainForm *MainForm;

//---------------------------------------------------------------------------

#endif
