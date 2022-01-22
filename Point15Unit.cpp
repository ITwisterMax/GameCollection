//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Point15Unit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TPoint15_Form *Point15_Form;

//---------------------------------------------------------------------------

__fastcall TPoint15_Form::TPoint15_Form(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------



// +-----------------+
// |                 |
// | Игра "Пятнашки" |
// |			     |
// +-----------------+

struct Position
{
	int xPos;
	int yPos;
};

struct Position PosArray[15];
int MX, MY;
int XEmpty, YEmpty;

//---------------------------------------------------------------------------

void __fastcall TPoint15_Form::FindEmptyPos()
{
	int x, y, i;
	int dx, dy;
	int f;

	for (y = 0; y <= 3; y++)
		for (x = 0; x <= 3; x++)
		{
			dx = x * Image1->Width + 2;
			dy = y * Image1->Height + 2;
			f = 0;

			for (i = 0; i <= 14; i++)
				if ((PosArray[i].xPos == dx) && (PosArray[i].yPos == dy))
				{
					f = 1;
					break;
				}

			if (f == 0)
			{
				XEmpty = dx;
				YEmpty = dy;
				break;
			}
		}
}

//---------------------------------------------------------------------------

void __fastcall TPoint15_Form::RandomPos()
{
	int k;
	int x, y;

	Randomize();

	//Ищем картинки, их координаты и ставим на рандомные места
	Label1: ;
	x = (Random(4)) * Image1->Width + 2;
	y = (Random(4)) * Image1->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label1;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image1->Left = x;
	Image1->Top = y;

	Label2: ;
	x = (Random(4)) * Image2->Width + 2;
	y = (Random(4)) * Image2->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label2;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image2->Left = x;
	Image2->Top = y;

	Label3: ;
	x = (Random(4)) * Image3->Width + 2;
	y = (Random(4)) * Image3->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label3;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image3->Left = x;
	Image3->Top = y;

	Label4: ;
	x = (Random(4)) * Image4->Width + 2;
	y = (Random(4)) * Image4->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label4;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image4->Left = x;
	Image4->Top = y;

	Label5: ;
	x = (Random(4)) * Image5->Width + 2;
	y = (Random(4)) * Image5->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label5;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image5->Left = x;
	Image5->Top = y;

	Label6: ;
	x = (Random(4)) * Image6->Width + 2;
	y = (Random(4)) * Image6->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label6;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image6->Left = x;
	Image6->Top = y;

	Label7: ;
	x = (Random(4)) * Image7->Width + 2;
	y = (Random(4)) * Image7->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label7;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image7->Left = x;
	Image7->Top = y;

	Label8: ;
	x = (Random(4)) * Image8->Width + 2;
	y = (Random(4)) * Image8->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label8;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image8->Left = x;
	Image8->Top = y;

	Label9: ;
	x = (Random(4)) * Image9->Width + 2;
	y = (Random(4)) * Image9->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label9;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image9->Left = x;
	Image9->Top = y;

	Label10: ;
	x = (Random(4)) * Image10->Width + 2;
	y = (Random(4)) * Image10->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label10;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image10->Left = x;
	Image10->Top = y;

	Label11: ;
	x = (Random(4)) * Image11->Width + 2;
	y = (Random(4)) * Image11->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label11;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image11->Left = x;
	Image11->Top = y;

	Label12: ;
	x = (Random(4)) * Image12->Width + 2;
	y = (Random(4)) * Image12->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label12;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image12->Left = x;
	Image12->Top = y;


	Label13: ;
	x = (Random(4)) * Image13->Width + 2;
	y = (Random(4)) * Image13->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label13;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image13->Left = x;
	Image13->Top = y;

	Label14: ;
	x = (Random(4)) * Image14->Width + 2;
	y = (Random(4)) * Image14->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label14;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image14->Left = x;
	Image14->Top = y;

	Label15: ;
	x = (Random(4)) * Image15->Width + 2;
	y = (Random(4)) * Image15->Height + 2;

	for (k = 0; k <= 14; k++)
		if ((x == PosArray[k].xPos) && (y == PosArray[k].yPos)) goto Label15;

	k = 0;
	while ((PosArray[k].xPos != 0) && (PosArray[k].yPos != 0)) k++;

	PosArray[k].xPos = x;
	PosArray[k].yPos = y;

	Image15->Left = x;
	Image15->Top = y;

	FindEmptyPos();
}

//---------------------------------------------------------------------------

void __fastcall TPoint15_Form::MyClick(TObject *Sender)
{
	int i, d;

	if ((((TImage *)(Sender))->Left - 62 == XEmpty) && (((TImage *)(Sender))->Top == YEmpty))
	{
		d = ((TImage *)(Sender))->Left;
		XEmpty = ((TImage *)(Sender))->Left;

		for (i = 1; i <= 31; i++)
		{
			d -= 2;
			((TImage *)(Sender))->Left = d;
			Application->ProcessMessages();
		}

		Steps->Caption = IntToStr(StrToInt(Steps->Caption) + 1);
		EndGame();
	}
	else
		if ((((TImage *)(Sender))->Left == XEmpty) && (((TImage *)(Sender))->Top - 62 == YEmpty))
		{
			d = ((TImage *)(Sender))->Top;
			YEmpty = ((TImage *)(Sender))->Top;

			for (i = 1; i <= 31; i++)
			{
				d -= 2;
				((TImage *)(Sender))->Top = d;
				Application->ProcessMessages();
			}

			Steps->Caption = IntToStr(StrToInt(Steps->Caption) + 1);
			EndGame();
		}
		else
			if ((((TImage *)(Sender))->Left + 62 == XEmpty) && (((TImage *)(Sender))->Top == YEmpty))
			{
				d = ((TImage *)(Sender))->Left;
				XEmpty = ((TImage *)(Sender))->Left;

				for (i = 1; i <= 31; i++)
				{
					d += 2;
					((TImage *)(Sender))->Left = d;
					Application->ProcessMessages();
				}

				Steps->Caption = IntToStr(StrToInt(Steps->Caption) + 1);
				EndGame();
			}
			else
				if ((((TImage *)(Sender))->Left == XEmpty) && (((TImage *)(Sender))->Top + 62 == YEmpty))
				{
					d = ((TImage *)(Sender))->Top;
					YEmpty = ((TImage *)(Sender))->Top;

					for (i = 1; i <= 31; i++)
					{
						d += 2;
						((TImage *)(Sender))->Top = d;
						Application->ProcessMessages();
					}

					Steps->Caption = IntToStr(StrToInt(Steps->Caption) + 1);
					EndGame();
				}
}

//---------------------------------------------------------------------------

void __fastcall TPoint15_Form::EndGame()
{
	int i, s = 0;

	if ((Image1->Left == 2) && (Image1->Top == 2)) s++;
	if ((Image2->Left == 1 * Image1->Width + 2) && (Image2->Top == 2)) s++;
	if ((Image3->Left == 2 * Image1->Width + 2) && (Image3->Top == 2)) s++;
	if ((Image4->Left == 3 * Image1->Width + 2) && (Image4->Top == 2)) s++;
	if ((Image5->Left == 2) && (Image5->Top == 1 * Image1->Height + 2)) s++;
	if ((Image6->Left == 1 * Image1->Width + 2) && (Image6->Top == 1 * Image1->Height + 2)) s++;
	if ((Image7->Left == 2 * Image1->Width + 2) && (Image7->Top == 1 * Image1->Height + 2)) s++;
	if ((Image8->Left == 3 * Image1->Width + 2) && (Image8->Top == 1 * Image1->Height + 2)) s++;
	if ((Image9->Left == 2) && (Image9->Top == 2 * Image1->Height + 2)) s++;
	if ((Image10->Left == 1 * Image1->Width + 2) && (Image10->Top == 2 * Image1->Height + 2)) s++;
	if ((Image11->Left == 2 * Image1->Width + 2) && (Image11->Top == 2 * Image1->Height + 2)) s++;
	if ((Image12->Left == 3 * Image1->Width + 2) && (Image12->Top == 2 * Image1->Height + 2)) s++;
	if ((Image13->Left == 2) && (Image13->Top == 3 * Image1->Height + 2)) s++;
	if ((Image14->Left == 1 * Image1->Width + 2) && (Image14->Top == 3 * Image1->Height + 2)) s++;
	if ((Image15->Left == 2 * Image1->Width + 2) && (Image15->Top == 3 * Image1->Height + 2)) s++;

	if (s == 15)
	{
        //Определение лучшего счета
		if ((StrToInt(Steps->Caption) < StrToInt(BestScore->Caption)) || (BestScore->Caption == "0"))
		{
			BestScore->Caption = Steps->Caption;
		}

		//Определение выигрыша
		int num;
		if (StrToInt(Steps->Caption) < 100) num = 10;
		else if (StrToInt(Steps->Caption) < 200) num = 9;
		else if (StrToInt(Steps->Caption) < 300) num = 8;
		else if (StrToInt(Steps->Caption) < 400) num = 7;
		else if (StrToInt(Steps->Caption) < 500) num = 6;
		else if (StrToInt(Steps->Caption) < 600) num = 5;
		else if (StrToInt(Steps->Caption) < 700) num = 4;
		else if (StrToInt(Steps->Caption) < 800) num = 3;
		else if (StrToInt(Steps->Caption) < 900) num = 2;
		else if (StrToInt(Steps->Caption) < 1000) num = 1;
		else num = 0;

		//Пересчет денег
		ShowMessage("You win " + IntToStr(num) + " $!");
		Money->Caption = IntToStr(StrToInt(Money->Caption) + num);

		//Обнуление массива позиций
		for (i = 0; i <= 14; i++)
		{
			PosArray[i].xPos = 0;
			PosArray[i].yPos = 0;
		}

		//Обнуление
		Steps->Caption = "0";
		RandomPos();
	}
}

//---------------------------------------------------------------------------

void __fastcall TPoint15_Form::FormShow(TObject *Sender)
{
	int i;

	//Устанавливаем фокус
	Point15_Cancel->SetFocus();

	//Начальные значения
	Steps->Caption = "0";
	Money->Caption = "0";

	//Обнуление массива позиций
    for (i = 0; i <= 14; i++)
		{
			PosArray[i].xPos = 0;
			PosArray[i].yPos = 0;
		}

    //Начальные положения объектов
	Image1->Left = 2;
	Image1->Top = 2;
	Image2->Left = 1 * Image1->Width + 2;
	Image2->Top = 2;
	Image3->Left = 2 * Image1->Width + 2;
	Image3->Top = 2;
	Image4->Left = 3 * Image1->Width + 2;
	Image4->Top = 2;
	Image5->Left = 2;
	Image5->Top = 1 * Image1->Height + 2;
	Image6->Left = 1 * Image1->Width + 2;
	Image6->Top = 1 * Image1->Height + 2;
	Image7->Left = 2 * Image1->Width + 2;
	Image7->Top = 1 * Image1->Height + 2;
	Image8->Left = 3 * Image1->Width + 2;
	Image8->Top = 1 * Image1->Height + 2;
	Image9->Left = 2;
	Image9->Top = 2 * Image1->Height + 2;
	Image10->Left = 1 * Image1->Width + 2;
	Image10->Top = 2 * Image1->Height + 2;
	Image11->Left = 2 * Image1->Width + 2;
	Image11->Top = 2 * Image1->Height + 2;
	Image12->Left = 3 * Image1->Width + 2;
	Image12->Top = 2 * Image1->Height + 2;
	Image13->Left = 2;
	Image13->Top = 3 * Image1->Height + 2;
	Image14->Left = 1 * Image1->Width + 2;
	Image14->Top = 3 * Image1->Height + 2;
	Image15->Left = 2 * Image1->Width + 2;
	Image15->Top = 3 * Image1->Height + 2;

	XEmpty = -1;
	YEmpty = -1;

    //Загрузка лучшего результата
	TStringList *BestScoreList = new TStringList();
	BestScoreList->LoadFromFile("Point15\\Point15BestScore.txt");

	AnsiString Name, TempName = "", buf, score = "";
	int j;
	Name = MainForm->Player2->Caption;

	for (i = 0; i < BestScoreList->Count; i++)
	{
		buf = BestScoreList->Strings[i];
		j = 1;
		TempName = "";
		while (buf[j] != ' ')
		{
			TempName += buf[j];
			j++;
		}
		TempName += buf[j];
		j++;

		if (Name == TempName)
		{
			while (j <= buf.Length())
			{
				score += buf[j];
				j++;

			}
			break;
		}
	}
	if (i == BestScoreList->Count)
	{
		score = "0";
	}

    //Записываем его
	BestScore->Caption = score;
}

//---------------------------------------------------------------------------

void __fastcall TPoint15_Form::Point15_NewGameClick(TObject *Sender)
{
	int i;

	//Обнуление массива позиций
	for (i = 0; i <= 14; i++)
	{
		PosArray[i].xPos = 0;
		PosArray[i].yPos = 0;
	}

	//Обнуление счета
	Steps->Caption = "0";

	RandomPos();
}

//---------------------------------------------------------------------------

void __fastcall TPoint15_Form::Point15_CancelClick(TObject *Sender)
{
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

    //Запись лучшего счета в файл
	nameFF = "";
	name = MainForm->Player2->Caption;

	TStringList *BestScoreList = new TStringList();
	BestScoreList->LoadFromFile("Point15\\Point15BestScore.txt");

	buf1 = name + BestScore->Caption;

	for (i = 0; i < BestScoreList->Count; i++)
	{
		buf2 = BestScoreList->Strings[i];

		j = 1;
		nameFF = "";
		while (buf2[j] != ' ')
		{
			nameFF = nameFF + buf2[j];
			j++;
		}
		nameFF = nameFF + buf2[j];

		if (name == nameFF)
		{
			BestScoreList->Strings[i] = buf1;
			break;
		}
	}

	if (i == BestScoreList->Count)
	{
        BestScoreList->Add(buf1);
	}

	BestScoreList->SaveToFile("Point15\\Point15BestScore.txt");

	//Выход
	ModalResult = mrCancel;
}

//---------------------------------------------------------------------------
