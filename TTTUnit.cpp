//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "TTTUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TTTT_Form *TTT_Form;

//---------------------------------------------------------------------------

__fastcall TTTT_Form::TTTT_Form(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------





// +------------------------+
// |                        |
// | Игра "Крестики-нолики" |
// |			            |
// +------------------------+

int a, i;

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Panel1Click(TObject *Sender)
{
    //Ход игрока
	if (Panel1->Caption == "")
	{
		Panel1->Caption = "X";
		Button1->Click();
		i = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Panel2Click(TObject *Sender)
{
	//Ход игрока
	if (Panel2->Caption == "")
	{
		Panel2->Caption = "X";
		Button1->Click();
		i = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Panel3Click(TObject *Sender)
{
	//Ход игрока
    if (Panel3->Caption == "")
	{
		Panel3->Caption = "X";
		Button1->Click();
		i = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Panel4Click(TObject *Sender)
{
	//Ход игрока
	if (Panel4->Caption == "")
	{
		Panel4->Caption = "X";
		Button1->Click();
		i = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Panel5Click(TObject *Sender)
{
	//Ход игрока
    if (Panel5->Caption == "")
	{
		Panel5->Caption = "X";
		Button1->Click();
		i = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Panel6Click(TObject *Sender)
{
	//Ход игрока
	if (Panel6->Caption == "")
	{
		Panel6->Caption = "X";
		Button1->Click();
		i = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Panel7Click(TObject *Sender)
{
	//Ход игрока
	if (Panel7->Caption == "")
	{
		Panel7->Caption = "X";
		Button1->Click();
		i = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Panel8Click(TObject *Sender)
{
	//Ход игрока
	if (Panel8->Caption == "")
	{
		Panel8->Caption = "X";
		Button1->Click();
		i = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Panel9Click(TObject *Sender)
{
	//Ход игрока
	if (Panel9->Caption == "")
	{
		Panel9->Caption = "X";
		Button1->Click();
		i = 0;
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::Button1Click(TObject *Sender)
{
	if (i == 0)
	do
	{
        //Определение выигрыша игрока
		if (Panel1->Caption == "X")
			if (Panel2->Caption == "X")
				if (Panel3->Caption == "X")
				{
					ShowMessage("You win 2 $!");
					Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
					TTT_YourScore->Caption = IntToStr(StrToInt(TTT_YourScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel4->Caption == "X")
			if (Panel5->Caption == "X")
				if (Panel6->Caption == "X")
				{
					ShowMessage("You win 2 $!");
					Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
					TTT_YourScore->Caption = IntToStr(StrToInt(TTT_YourScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel7->Caption == "X")
			if (Panel8->Caption == "X")
				if (Panel9->Caption == "X")
				{
					ShowMessage("You win 2 $!");
					Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
					TTT_YourScore->Caption = IntToStr(StrToInt(TTT_YourScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel1->Caption == "X")
			if (Panel5->Caption == "X")
				if (Panel9->Caption == "X")
				{
					ShowMessage("You win 2 $!");
					Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
					TTT_YourScore->Caption = IntToStr(StrToInt(TTT_YourScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel3->Caption == "X")
			if (Panel5->Caption == "X")
				if (Panel7->Caption == "X")
				{
					ShowMessage("You win 2 $!");
					Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
					TTT_YourScore->Caption = IntToStr(StrToInt(TTT_YourScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel1->Caption == "X")
			if (Panel4->Caption == "X")
				if (Panel7->Caption == "X")
				{
					ShowMessage("You win 2 $!");
					Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
					TTT_YourScore->Caption = IntToStr(StrToInt(TTT_YourScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel2->Caption == "X")
			if (Panel5->Caption == "X")
				if (Panel8->Caption == "X")
				{
					ShowMessage("You win 2 $!");
					Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
					TTT_YourScore->Caption = IntToStr(StrToInt(TTT_YourScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel3->Caption == "X")
			if (Panel6->Caption == "X")
				if (Panel9->Caption == "X")
				{
					ShowMessage("You win 2 $!");
					Money->Caption = IntToStr(StrToInt(Money->Caption) + 2);
					TTT_YourScore->Caption = IntToStr(StrToInt(TTT_YourScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}

        //Выигрышный ход компьютера
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel2->Caption == "O")
					if (Panel3->Caption == "")
					{
						Panel3->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel2->Caption == "")
					if (Panel3->Caption == "O")
					{
						Panel2->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "")
				if (Panel2->Caption == "O")
					if (Panel3->Caption == "O")
					{
						Panel1->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel4->Caption == "O")
				if (Panel5->Caption == "O")
					if (Panel6->Caption == "")
					{
						Panel6->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel4->Caption == "O")
				if (Panel5->Caption == "")
					if (Panel6->Caption == "O")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel4->Caption == "")
				if (Panel5->Caption == "O")
					if (Panel6->Caption == "O")
					{
						Panel4->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel7->Caption == "O")
				if (Panel8->Caption == "O")
					if (Panel9->Caption == "")
					{
						Panel9->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel7->Caption == "O")
				if (Panel8->Caption == "")
					if (Panel9->Caption == "O")
					{
						Panel8->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel7->Caption == "")
				if (Panel8->Caption == "O")
					if (Panel9->Caption == "O")
					{
						Panel7->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel4->Caption == "O")
					if (Panel7->Caption == "")
					{
						Panel7->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel4->Caption == "")
					if (Panel7->Caption == "O")
					{
						Panel4->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "")
				if (Panel4->Caption == "O")
					if (Panel7->Caption == "O")
					{
						Panel1->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel2->Caption == "O")
				if (Panel5->Caption == "O")
					if (Panel8->Caption == "")
					{
						Panel8->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel2->Caption == "O")
				if (Panel5->Caption == "")
					if (Panel8->Caption == "O")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel2->Caption == "")
				if (Panel5->Caption == "O")
					if (Panel8->Caption == "O")
					{
						Panel2->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "O")
				if (Panel6->Caption == "O")
					if (Panel9->Caption == "")
					{
						Panel9->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "O")
				if (Panel6->Caption == "")
					if (Panel9->Caption == "O")
					{
						Panel6->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "")
				if (Panel6->Caption == "O")
					if (Panel9->Caption == "O")
					{
						Panel3->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel5->Caption == "O")
					if (Panel9->Caption == "")
					{
						Panel9->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel5->Caption == "")
					if (Panel9->Caption == "O")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "")
				if (Panel5->Caption == "O")
					if (Panel9->Caption == "O")
					{
						Panel1->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "O")
				if (Panel5->Caption == "O")
					if (Panel7->Caption == "")
					{
						Panel7->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "O")
				if (Panel5->Caption == "")
					if (Panel7->Caption == "O")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "")
				if (Panel5->Caption == "O")
					if (Panel7->Caption == "O")
					{
						Panel3->Caption = "O";
						i = 1;
					}

        if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel2->Caption == "O")
					if (Panel3->Caption == "")
					{
						Panel3->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel2->Caption == "")
					if (Panel3->Caption == "O")
					{
						Panel2->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "")
				if (Panel2->Caption == "O")
					if (Panel3->Caption == "O")
					{
						Panel1->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel4->Caption == "O")
				if (Panel5->Caption == "O")
					if (Panel6->Caption == "")
					{
						Panel6->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel4->Caption == "O")
				if (Panel5->Caption == "")
					if (Panel6->Caption == "O")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel4->Caption == "")
				if (Panel5->Caption == "O")
					if (Panel6->Caption == "O")
					{
						Panel4->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel7->Caption == "O")
				if (Panel8->Caption == "O")
					if (Panel9->Caption == "")
					{
						Panel9->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel7->Caption == "O")
				if (Panel8->Caption == "")
					if (Panel9->Caption == "O")
					{
						Panel8->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel7->Caption == "")
				if (Panel8->Caption == "O")
					if (Panel9->Caption == "O")
					{
						Panel7->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel4->Caption == "O")
					if (Panel7->Caption == "")
					{
						Panel7->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel4->Caption == "")
					if (Panel7->Caption == "O")
					{
						Panel4->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "")
				if (Panel4->Caption == "O")
					if (Panel7->Caption == "O")
					{
						Panel1->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel2->Caption == "O")
				if (Panel5->Caption == "O")
					if (Panel8->Caption == "")
					{
						Panel8->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel2->Caption == "O")
				if (Panel5->Caption == "")
					if (Panel8->Caption == "O")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel2->Caption == "")
				if (Panel5->Caption == "O")
					if (Panel8->Caption == "O")
					{
						Panel2->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "O")
				if (Panel6->Caption == "O")
					if (Panel9->Caption == "")
					{
						Panel9->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "O")
				if (Panel6->Caption == "")
					if (Panel9->Caption == "O")
					{
						Panel6->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "")
				if (Panel6->Caption == "O")
					if (Panel9->Caption == "O")
					{
						Panel3->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel5->Caption == "O")
					if (Panel9->Caption == "")
					{
						Panel9->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "O")
				if (Panel5->Caption == "")
					if (Panel9->Caption == "O")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "")
				if (Panel5->Caption == "O")
					if (Panel9->Caption == "O")
					{
						Panel1->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "O")
				if (Panel5->Caption == "O")
					if (Panel7->Caption == "")
					{
						Panel7->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "O")
				if (Panel5->Caption == "")
					if (Panel7->Caption == "O")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "")
				if (Panel5->Caption == "O")
					if (Panel7->Caption == "O")
					{
						Panel3->Caption = "O";
						i = 1;
					}

		//Ход компьютера, мешающий игроку
		if (i == 0)
			if (Panel1->Caption == "X")
				if (Panel2->Caption == "X")
					if (Panel3->Caption == "")
					{
						Panel3->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "X")
				if (Panel2->Caption == "")
					if (Panel3->Caption == "X")
					{
						Panel2->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "")
				if (Panel2->Caption == "X")
					if (Panel3->Caption == "X")
					{
						Panel1->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel4->Caption == "X")
				if (Panel5->Caption == "X")
					if (Panel6->Caption == "")
					{
						Panel6->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel4->Caption == "X")
				if (Panel5->Caption == "")
					if (Panel6->Caption == "X")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel4->Caption == "")
				if (Panel5->Caption == "X")
					if (Panel6->Caption == "X")
					{
						Panel4->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel7->Caption == "X")
				if (Panel8->Caption == "X")
					if (Panel9->Caption == "")
					{
						Panel9->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel7->Caption == "X")
				if (Panel8->Caption == "")
					if (Panel9->Caption == "X")
					{
						Panel8->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel7->Caption == "")
				if (Panel8->Caption == "X")
					if (Panel9->Caption == "X")
					{
						Panel7->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "X")
				if (Panel4->Caption == "X")
					if (Panel7->Caption == "")
					{
						Panel7->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "X")
				if (Panel4->Caption == "")
					if (Panel7->Caption == "X")
					{
						Panel4->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "")
				if (Panel4->Caption == "X")
					if (Panel7->Caption == "X")
					{
						Panel1->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel2->Caption == "X")
				if (Panel5->Caption == "X")
					if (Panel8->Caption == "")
					{
						Panel8->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel2->Caption == "X")
				if (Panel5->Caption == "")
					if (Panel8->Caption == "X")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel2->Caption == "")
				if (Panel5->Caption == "X")
					if (Panel8->Caption == "X")
					{
						Panel2->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "X")
				if (Panel6->Caption == "X")
					if (Panel9->Caption == "")
					{
						Panel9->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "X")
				if (Panel6->Caption == "")
					if (Panel9->Caption == "X")
					{
						Panel6->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "")
				if (Panel6->Caption == "X")
					if (Panel9->Caption == "X")
					{
						Panel3->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "X")
				if (Panel5->Caption == "X")
					if (Panel9->Caption == "")
					{
						Panel9->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "X")
				if (Panel5->Caption == "")
					if (Panel9->Caption == "X")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel1->Caption == "")
				if (Panel5->Caption == "X")
					if (Panel9->Caption == "X")
					{
						Panel1->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "X")
				if (Panel5->Caption == "X")
					if (Panel7->Caption == "")
					{
						Panel7->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "X")
				if (Panel5->Caption == "")
					if (Panel7->Caption == "X")
					{
						Panel5->Caption = "O";
						i = 1;
					}
		if (i == 0)
			if (Panel3->Caption == "")
				if (Panel5->Caption == "X")
					if (Panel7->Caption == "X")
					{
						Panel3->Caption = "O";
						i = 1;
					}

		//Рандомный ход компьютера
		if (i == 0)
			if (Panel1->Caption == "")
			{
				a = Random(2);
				if (a == 1)
				{
					Panel1->Caption = "O";
					i = 1;
				}
			}
		if (i == 0)
			if (Panel2->Caption == "")
			{
				a = Random(2);
				if (a == 1)
				{
					Panel2->Caption = "O";
					i = 1;
				}
			}
		if (i == 0)
			if (Panel3->Caption == "")
			{
				a = Random(2);
				if (a == 1)
				{
					Panel3->Caption = "O";
					i = 1;
				}
			}
		if (i == 0)
			if (Panel4->Caption == "")
			{
				a = Random(2);
				if (a == 1)
				{
					Panel4->Caption = "O";
					i = 1;
				}
			}
		if (i == 0)
			if (Panel5->Caption == "")
			{
				a = Random(2);
				if (a == 1)
				{
					Panel5->Caption = "O";
					i = 1;
				}
			}
		if (i == 0)
			if (Panel6->Caption == "")
			{
				a = Random(2);
				if (a == 1)
				{
					Panel6->Caption = "O";
					i = 1;
				}
			}
		if (i == 0)
			if (Panel7->Caption == "")
			{
				a = Random(2);
				if (a == 1)
				{
					Panel7->Caption = "O";
					i = 1;
				}
			}
		if (i == 0)
			if (Panel8->Caption == "")
			{
				a = Random(2);
				if (a == 1)
				{
					Panel8->Caption = "O";
					i = 1;
				}
			}
		if (i == 0)
			if (Panel9->Caption == "")
			{
				a = Random(2);
				if (a == 1)
				{
					Panel9->Caption = "O";
					i = 1;
				}
			}
		if (i == 0)
		{
			if (Panel1->Caption == "") Panel1->Caption = "O";
			else if (Panel2->Caption == "") Panel2->Caption = "O";
			else if (Panel3->Caption == "") Panel3->Caption = "O";
			else if (Panel4->Caption == "") Panel4->Caption = "O";
			else if (Panel5->Caption == "") Panel5->Caption = "O";
			else if (Panel6->Caption == "") Panel6->Caption = "O";
			else if (Panel7->Caption == "") Panel7->Caption = "O";
			else if (Panel8->Caption == "") Panel8->Caption = "O";
			else if (Panel9->Caption == "") Panel9->Caption = "O";
            i = 1;
		}

		//Определение выигрыша компьютера
		if (Panel1->Caption == "O")
			if (Panel2->Caption == "O")
				if (Panel3->Caption == "O")
				{
					ShowMessage("You lose 1 $!");
					if (Money->Caption != "0")
						Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
					TTT_ComputerScore->Caption = IntToStr(StrToInt(TTT_ComputerScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel4->Caption == "O")
			if (Panel5->Caption == "O")
				if (Panel6->Caption == "O")
				{
					ShowMessage("You lose 1 $!");
					if (Money->Caption != "0")
						Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
					TTT_ComputerScore->Caption = IntToStr(StrToInt(TTT_ComputerScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel7->Caption == "O")
			if (Panel8->Caption == "O")
				if (Panel9->Caption == "O")
				{
					ShowMessage("You lose 1 $!");
					if (Money->Caption != "0")
						Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
					TTT_ComputerScore->Caption = IntToStr(StrToInt(TTT_ComputerScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel1->Caption == "O")
			if (Panel5->Caption == "O")
				if (Panel9->Caption == "O")
				{
					ShowMessage("You lose 1 $!");
					if (Money->Caption != "0")
						Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
					TTT_ComputerScore->Caption = IntToStr(StrToInt(TTT_ComputerScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel3->Caption == "O")
			if (Panel5->Caption == "O")
				if (Panel7->Caption == "O")
				{
					ShowMessage("You lose 1 $!");
					if (Money->Caption != "0")
						Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
					TTT_ComputerScore->Caption = IntToStr(StrToInt(TTT_ComputerScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel1->Caption == "O")
			if (Panel4->Caption == "O")
				if (Panel7->Caption == "O")
				{
					ShowMessage("You lose 1 $!");
					if (Money->Caption != "0")
						Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
					TTT_ComputerScore->Caption = IntToStr(StrToInt(TTT_ComputerScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel2->Caption == "O")
			if (Panel5->Caption == "O")
				if (Panel8->Caption == "O")
				{
					ShowMessage("You lose 1 $!");
					if (Money->Caption != "0")
						Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
					TTT_ComputerScore->Caption = IntToStr(StrToInt(TTT_ComputerScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}
		if (Panel3->Caption == "O")
			if (Panel6->Caption == "O")
				if (Panel9->Caption == "O")
				{
					ShowMessage("You lose 1 $!");
					if (Money->Caption != "0")
						Money->Caption = IntToStr(StrToInt(Money->Caption) - 1);
					TTT_ComputerScore->Caption = IntToStr(StrToInt(TTT_ComputerScore->Caption) + 1);
					TTT_NewGame->Click();
					i = 1;
				}

        //Определение ничьей
		if (Panel1->Caption != "")
		if (Panel2->Caption != "")
		if (Panel3->Caption != "")
		if (Panel4->Caption != "")
		if (Panel5->Caption != "")
		if (Panel6->Caption != "")
		if (Panel7->Caption != "")
		if (Panel8->Caption != "")
		if (Panel9->Caption != "")
		{
            ShowMessage("Oh, tie!");
			TTT_NewGame->Click();
			i = 1;
        }
	}
	while (i != 1);
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::FormShow(TObject *Sender)
{
    //Обнуление
	Money->Caption = "0";
	TTT_YourScore->Caption = "0";
	TTT_ComputerScore->Caption = "0";

	//Обновление площадки
    Panel1->Caption = "";
	Panel2->Caption = "";
	Panel3->Caption = "";
	Panel4->Caption = "";
	Panel5->Caption = "";
	Panel6->Caption = "";
	Panel7->Caption = "";
	Panel8->Caption = "";
	Panel9->Caption = "";

	Randomize();
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::TTT_NewGameClick(TObject *Sender)
{
	int x;

	//Обновление площадки
	Panel1->Caption = "";
	Panel2->Caption = "";
	Panel3->Caption = "";
	Panel4->Caption = "";
	Panel5->Caption = "";
	Panel6->Caption = "";
	Panel7->Caption = "";
	Panel8->Caption = "";
	Panel9->Caption = "";

    //Рандомный ход компьютера
	a = Random(2);
	if (a == 1)
	{
		x = Random(10);
		if (x == 1) Panel1->Caption = "O";
		if (x == 2) Panel2->Caption = "O";
		if (x == 3) Panel3->Caption = "O";
		if (x == 4) Panel4->Caption = "O";
		if (x == 5) Panel5->Caption = "O";
		if (x == 6) Panel6->Caption = "O";
		if (x == 7) Panel7->Caption = "O";
		if (x == 8) Panel8->Caption = "O";
		if (x == 9) Panel9->Caption = "O";
	}
}

//---------------------------------------------------------------------------

void __fastcall TTTT_Form::TTT_CancelClick(TObject *Sender)
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
