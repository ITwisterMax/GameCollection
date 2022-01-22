//---------------------------------------------------------------------------

#ifndef AccountUnitH
#define AccountUnitH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Menus.hpp>

#include "MainUnit.h"

//---------------------------------------------------------------------------

class TAccountForm : public TForm
{
__published:	// IDE-managed Components

    //Редактирование аккаунтов
	TImage *BackGround;
	TListBox *PlayerAccount;
	TButton *Add;
	TButton *Delete;
	TButton *Cancel;

	//Процедуры и функции
	void __fastcall CancelClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);

private:	// User declarations
public:		// User declarations

	__fastcall TAccountForm(TComponent* Owner);
};

//---------------------------------------------------------------------------

extern PACKAGE TAccountForm *AccountForm;

//---------------------------------------------------------------------------

#endif
