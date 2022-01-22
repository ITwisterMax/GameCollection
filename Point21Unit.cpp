//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Point21Unit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TPoint21_Form *Point21_Form;

//---------------------------------------------------------------------------

__fastcall TPoint21_Form::TPoint21_Form(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------





// +----------------+
// |                |
// | Игра "21 очко" |
// |			    |
// +----------------+

int Score, ScoreE;
int Cards, CardsE;

//---------------------------------------------------------------------------

void __fastcall TPoint21_Form::Point21_EndGame()
{
    //Поиск победителей/проигравших и пересчет текущего баланса
	if (((Score > 21) && (ScoreE > 21)) || (Score == ScoreE))
	{
		ShowMessage("Oh, tie!");
	}
	else if (Score > 21)
	{
		ShowMessage("You lose 1 $!");
		if (StrToInt(Money->Caption) != 0)
			Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
		else Money->Caption = "0";
	}
	else if (ScoreE > 21)
	{
		ShowMessage("You win 2 $!");
		Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
	}
	else if (Score < ScoreE)
	{
		ShowMessage("You lose 1 $!");
		if (StrToInt(Money->Caption) != 0)
			Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
		else Money->Caption = "0";
	}
	else if (Score > ScoreE)
	{
		ShowMessage("You win 2 $!");
		Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
	}
}

//---------------------------------------------------------------------------

void __fastcall TPoint21_Form::Point21_ResetImages()
{
	int i;

	//Обнуление
	for (i = 1; i <= 18; i++)
	{
		((TImage *)(FindComponent("Point21_Image" + IntToStr(i))))->Picture = NULL;
		((TImage *)(FindComponent("Point21_Image" + IntToStr(i))))->Tag = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TPoint21_Form::Point21_GetP()
{
	int CurrCard, i;

	//Рандомная карта
	CurrCard = Random(52);

	//Буферный компонент для рисунков
	if (CurrCard == 0) { Point21_Image8->Picture->LoadFromFile("Point21\\1.bmp"); CurrCard = 1; }
	else Point21_Image8->Picture->LoadFromFile("Point21\\" + IntToStr(CurrCard) + ".bmp");

	//Пересчет очков
	if ((CurrCard == 1) || (CurrCard == 14) || (CurrCard == 27) || (CurrCard == 40)) Score += 11;
	else if ((CurrCard == 2) || (CurrCard == 15) || (CurrCard == 28) || (CurrCard == 41)) Score += 2;
	else if ((CurrCard == 3) || (CurrCard == 16) || (CurrCard == 29) || (CurrCard == 42)) Score += 3;
	else if ((CurrCard == 4) || (CurrCard == 17) || (CurrCard == 30) || (CurrCard == 43)) Score += 4;
	else if ((CurrCard == 5) || (CurrCard == 18) || (CurrCard == 31) || (CurrCard == 44)) Score += 5;
	else if ((CurrCard == 6) || (CurrCard == 19) || (CurrCard == 32) || (CurrCard == 45)) Score += 6;
	else if ((CurrCard == 7) || (CurrCard == 20) || (CurrCard == 33) || (CurrCard == 46)) Score += 7;
	else if ((CurrCard == 8) || (CurrCard == 21) || (CurrCard == 34) || (CurrCard == 47)) Score += 8;
	else if ((CurrCard == 9) || (CurrCard == 22) || (CurrCard == 35) || (CurrCard == 48)) Score += 9;
	else if ((CurrCard == 10) || (CurrCard == 23) || (CurrCard == 36) || (CurrCard == 49)) Score += 10;
	else if ((CurrCard == 11) || (CurrCard == 24) || (CurrCard == 37) || (CurrCard == 50)) Score += 2;
	else if ((CurrCard == 12) || (CurrCard == 25) || (CurrCard == 38) || (CurrCard == 51)) Score += 3;
	else if ((CurrCard == 13) || (CurrCard == 26) || (CurrCard == 39) || (CurrCard == 52)) Score += 4;

    //Вывод рисунка карты
	if (Point21_Image1->Tag == 0)
	{
		Point21_Image1->Picture = Point21_Image8->Picture;
		Point21_Image1->Tag = 1;
	}
	else if (Point21_Image2->Tag == 0)
	{
		Point21_Image2->Picture = Point21_Image8->Picture;
		Point21_Image2->Tag = 1;
	}
	else if (Point21_Image3->Tag == 0)
	{
		Point21_Image3->Picture = Point21_Image8->Picture;
		Point21_Image3->Tag = 1;
	}
	else if (Point21_Image4->Tag == 0)
	{
		Point21_Image4->Picture = Point21_Image8->Picture;
		Point21_Image4->Tag = 1;
	}
	else if (Point21_Image5->Tag == 0)
	{
		Point21_Image5->Picture = Point21_Image8->Picture;
		Point21_Image5->Tag = 1;
	}
	else if (Point21_Image6->Tag == 0)
	{
		Point21_Image6->Picture = Point21_Image8->Picture;
		Point21_Image6->Tag = 1;
	}
	else if (Point21_Image7->Tag == 0)
	{
		Point21_Image7->Picture = Point21_Image8->Picture;
		Point21_Image7->Tag = 1;
	}
	else if (Point21_Image9->Tag == 0)
	{
		Point21_Image9->Picture = Point21_Image8->Picture;
		Point21_Image9->Tag = 1;
	}
}

//---------------------------------------------------------------------------

void __fastcall TPoint21_Form::Point21_Get()
{
	int CurrCard, i;

	//Рандомная карта
	CurrCard = Random(52);

	//Буферный компонент для рисунков
	if (CurrCard == 0) { Point21_Image17->Picture->LoadFromFile("Point21\\1.bmp"); CurrCard = 1; }
	else Point21_Image17->Picture->LoadFromFile("Point21\\" + IntToStr(CurrCard) + ".bmp");

	//Пересчет очков
	if ((CurrCard == 1) || (CurrCard == 14) || (CurrCard == 27) || (CurrCard == 40)) ScoreE += 11;
	else if ((CurrCard == 2) || (CurrCard == 15) || (CurrCard == 28) || (CurrCard == 41)) ScoreE += 2;
	else if ((CurrCard == 3) || (CurrCard == 16) || (CurrCard == 29) || (CurrCard == 42)) ScoreE += 3;
	else if ((CurrCard == 4) || (CurrCard == 17) || (CurrCard == 30) || (CurrCard == 43)) ScoreE += 4;
	else if ((CurrCard == 5) || (CurrCard == 18) || (CurrCard == 31) || (CurrCard == 44)) ScoreE += 5;
	else if ((CurrCard == 6) || (CurrCard == 19) || (CurrCard == 32) || (CurrCard == 45)) ScoreE += 6;
	else if ((CurrCard == 7) || (CurrCard == 20) || (CurrCard == 33) || (CurrCard == 46)) ScoreE += 7;
	else if ((CurrCard == 8) || (CurrCard == 21) || (CurrCard == 34) || (CurrCard == 47)) ScoreE += 8;
	else if ((CurrCard == 9) || (CurrCard == 22) || (CurrCard == 35) || (CurrCard == 48)) ScoreE+= 9;
	else if ((CurrCard == 10) || (CurrCard == 23) || (CurrCard == 36) || (CurrCard == 49)) ScoreE += 10;
	else if ((CurrCard == 11) || (CurrCard == 24) || (CurrCard == 37) || (CurrCard == 50)) ScoreE += 2;
	else if ((CurrCard == 12) || (CurrCard == 25) || (CurrCard == 38) || (CurrCard == 51)) ScoreE += 3;
	else if ((CurrCard == 13) || (CurrCard == 26) || (CurrCard == 39) || (CurrCard == 52)) ScoreE += 4;

	//Вывод рисунка карты
	if (Point21_Image10->Tag == 0)
	{
		Point21_Image10->Picture = Point21_Image17->Picture;
		Point21_Image10->Tag = 1;
	}
	else if (Point21_Image11->Tag == 0)
	{
		Point21_Image11->Picture = Point21_Image17->Picture;
		Point21_Image11->Tag = 1;
	}
	else if (Point21_Image12->Tag == 0)
	{
		Point21_Image12->Picture = Point21_Image17->Picture;
		Point21_Image12->Tag = 1;
	}
	else if (Point21_Image13->Tag == 0)
	{
		Point21_Image13->Picture = Point21_Image17->Picture;
		Point21_Image13->Tag = 1;
	}
	else if (Point21_Image14->Tag == 0)
	{
		Point21_Image14->Picture = Point21_Image17->Picture;
		Point21_Image14->Tag = 1;
	}
	else if (Point21_Image15->Tag == 0)
	{
		Point21_Image15->Picture = Point21_Image17->Picture;
		Point21_Image15->Tag = 1;
	}
	else if (Point21_Image16->Tag == 0)
	{
		Point21_Image16->Picture = Point21_Image17->Picture;
		Point21_Image16->Tag = 1;
	}
	else if (Point21_Image18->Tag == 0)
	{
		Point21_Image18->Picture = Point21_Image17->Picture;
		Point21_Image18->Tag = 1;
	}
}

//---------------------------------------------------------------------------

void __fastcall TPoint21_Form::FormShow(TObject *Sender)
{
	//Устанавливаем фокус
	Point21_Cancel->SetFocus();

    //Рандом
	Randomize();

	//Подготовка поля
	Money->Caption = "0";
	Point21_ResetImages();
    Score = ScoreE = 0;
	Cards = CardsE = 0;

	//Первые карты
	CardsE++;
	Point21_Get();

	Cards++;
	Point21_GetP();

    //Пересчет очков
    Point21_YourScore->Caption = IntToStr(Score);
	Point21_ComputerScore->Caption = IntToStr(ScoreE);
}

//---------------------------------------------------------------------------

void __fastcall TPoint21_Form::Point21_MoreClick(TObject *Sender)
{
	//Увеличиваем количество карт
	Cards++;
	if (Cards > 8) ShowMessage("Error! Too many cards...");
	else
	{
		//Берем еще
		Point21_GetP();
		//Перезаписываем счет
		Point21_YourScore->Caption = IntToStr(Score);
	}
}

//---------------------------------------------------------------------------

void __fastcall TPoint21_Form::Point21_StopClick(TObject *Sender)
{

	int n = Random(9);

	//Компьютер берет карты
	while (n < 9)
	{
		if (ScoreE < 10)
		{
			CardsE++;
			Point21_Get();
		}
		else if (random(20) > 10)
		{
			CardsE++;
			Point21_Get();
		}
		else goto Label;
	}

	Label :

	//Запись счета
	Point21_YourScore->Caption = IntToStr(Score);
	Point21_ComputerScore->Caption = IntToStr(ScoreE);

	//Конец игры
	Point21_EndGame();

	//Подготовка поля
	Point21_ResetImages();
	Score = ScoreE = 0;
	Cards = CardsE = 0;

	//Первые карты
	CardsE++;
	Point21_Get();

	Cards++;
	Point21_GetP();

	//Пересчет очков
	Point21_YourScore->Caption = IntToStr(Score);
	Point21_ComputerScore->Caption = IntToStr(ScoreE);
}

//---------------------------------------------------------------------------

void __fastcall TPoint21_Form::Point21_NewGameClick(TObject *Sender)
{
	//Подготовка поля
	Point21_ResetImages();
	Score = ScoreE = 0;
	Cards = CardsE = 0;

	//Первые карты
	CardsE++;
	Point21_Get();

	Cards++;
	Point21_GetP();

    //Обновляем очки
    Point21_YourScore->Caption = IntToStr(Score);
	Point21_ComputerScore->Caption = IntToStr(ScoreE);
}

//---------------------------------------------------------------------------

void __fastcall TPoint21_Form::Point21_CancelClick(TObject *Sender)
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

	//Выход
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

