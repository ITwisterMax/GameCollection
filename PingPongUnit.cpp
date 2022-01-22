//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "PingPongUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TPingPong_Form *PingPong_Form;

//---------------------------------------------------------------------------

__fastcall TPingPong_Form::TPingPong_Form(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------





// +------------------+
// |                  |
// | Игра "Пинг-понг" |
// |			      |
// +------------------+

int dx, dy;

//---------------------------------------------------------------------------

void __fastcall TPingPong_Form::Timer1Timer(TObject *Sender)
{
	TRect Overlay;

	//Движение шарика
	Ball->Left += dx;
	Ball->Top += dy;

	//Проверка на столкновение с верхней и нижней границей
	if ((Ball->Top <= 5) || (Ball->Top >= Panel->Height - 25))
		dy *= -1;

	//Проверка на столкновение с левой ракеткой
	if (IntersectRect(Overlay, BoardL->BoundsRect, Ball->BoundsRect)) dx *= -1;
	else if (Ball->Left < BoardL->Left - 15)
	{
		//Пересчет очков
		ComputerScore->Caption = IntToStr(StrToInt(ComputerScore->Caption) + 1);
		if (Money->Caption != 0)
			Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
		dx = -dx;
		Restart();
	}

	//Проверка на столкновение с правой ракеткой
	if (IntersectRect(Overlay, BoardR->BoundsRect, Ball->BoundsRect)) dx *= -1;
	else if (Ball->Left > BoardR->Left + 15)
	{
		//Пересчет очков
		YourScore->Caption = IntToStr(StrToInt(YourScore->Caption) + 1);
		Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
		dx = -dx;
		Restart();
	}
}

//---------------------------------------------------------------------------

void __fastcall TPingPong_Form::Timer2Timer(TObject *Sender)
{
	//Управление правой ракеткой (компьютер)
	if (Ball->Top >= BoardR->Top)
		if (BoardR->Top <= Panel->Height - 105) BoardR->Top += 9;
	if (Ball->Top <= BoardR->Top)
		if (BoardR->Top >= 5) BoardR->Top -= 9;
}

//---------------------------------------------------------------------------

void __fastcall TPingPong_Form::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	//Управление левой ракеткой (игрок)
	if (Key == VK_UP)
		if (BoardL->Top >= 5) BoardL->Top -= 9;
	if (Key == VK_DOWN)
		if (BoardL->Top <= Panel->Height - 105) BoardL->Top += 9;
}

//---------------------------------------------------------------------------

void __fastcall TPingPong_Form::Restart()
{
	//Стандартное положение объектов
	BoardL->Top = (Panel->Height - 80) / 2;
	BoardL->Left = 15;

	BoardR->Top = (Panel->Height - 80) / 2;
	BoardR->Left = Panel->Width - 35;

	Ball->Top = (Panel->Height - 20) / 2;
	Ball->Left = (Panel->Width - 28) / 2;

	//Скорость шарика
	if (dx > 0) {
		dx = 11;
		dy = 11;
		dx += Random(3);
		dy += Random(3);
	}
	else
	{
		dx = -11;
		dy = -11;
		dx -= Random(3);
		dy -= Random(3);
	}
}

//---------------------------------------------------------------------------

void __fastcall TPingPong_Form::FormShow(TObject *Sender)
{
	//Устанавливаем фокус
	PingPong_Cancel->SetFocus();
	PingPong_Form->SetFocusedControl(PingPong_Form);

	//Обнуление
	YourScore->Caption = "0";
	ComputerScore->Caption = "0";
	Money->Caption = "0";

	Randomize();
	Restart();
}

//---------------------------------------------------------------------------

void __fastcall TPingPong_Form::PingPong_NewGameClick(TObject *Sender)
{
    //Останавливаем таймер
	Timer1->Enabled = true;
	Timer2->Enabled = true;

    //Обнуление
	YourScore->Caption = "0";
	ComputerScore->Caption = "0";

	Restart();
    PingPong_Form->SetFocusedControl(PingPong_Form);
}

//---------------------------------------------------------------------------

void __fastcall TPingPong_Form::PingPong_CancelClick(TObject *Sender)
{
	//Останавливаем таймер
	Timer1->Enabled = false;
	Timer2->Enabled = false;

	AnsiString buf1 = Money->Caption, buf2 = "", buf3 = "";
	int i = 1, num;

	//Вычленяем общий баланс
	buf2 = MainForm->Money2->Caption;

	//Считаем сумму и перезаписываем баланс
	num = StrToInt(buf1) + StrToInt(buf2);
	if (num >= 99) num = 99;
	MainForm->Money2->Caption = IntToStr(num);

	//Обновляем информацию аккаунта (подробнее см. TMainForm::ResetClick)
	Money->Caption = MainForm->Money2->Caption;

	AnsiString nameFF = "", name = MainForm->Player2->Caption;
	int j;

	TStringList *List = new TStringList();
	List->LoadFromFile("Menu\\Info.txt");

	buf3 = MainForm->Temp->Caption;

	buf1 = name + "( " + IntToStr(num) + " $ ) ( " + buf3 + " )";

	for (i = 0; i < List->Count; i++)
	{
		buf2 = List->Strings[i];

		j = 1;
		nameFF = "";
		while (buf2[j] != '(')
		{
			nameFF = nameFF + buf2[j];
			j++;
		}

		if (name == nameFF)
		{
			List->Strings[i] = buf1;
			break;
		}
	}

	List->SaveToFile("Menu\\Info.txt");

	//Выход
	ModalResult = mrCancel;
}

//---------------------------------------------------------------------------
