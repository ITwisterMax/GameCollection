//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "WestUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TWest_Form *West_Form;

//---------------------------------------------------------------------------

__fastcall TWest_Form::TWest_Form(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------





// +--------------------+
// |                    |
// | ���� "����� �����" |
// |			        |
// +--------------------+

bool F;

//---------------------------------------------------------------------------

void __fastcall TWest_Form::EndGame()
{
	int num;
	//����������� ��������
	num = West_YourScore->Tag / 10;

	//����������� ������� �����
    if (StrToInt(West_YourScore->Caption) > StrToInt(BestScore->Caption))
	{
		BestScore->Caption = West_YourScore->Caption;
	}

    //�������� �����
	ShowMessage("You win " + IntToStr(num) + " $!");
	Money->Caption = IntToStr(StrToInt(Money->Caption) + num);
}

//---------------------------------------------------------------------------

void __fastcall TWest_Form::BackImageMouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
    //�������� ������
	if ((EnemyTimer->Enabled == true) && F)
	{
		Player->Left = X - Player->Width / 2;
		Player->Top = Y - Player->Height / 2;
	}
}

//---------------------------------------------------------------------------

void __fastcall TWest_Form::LevelTimerTimer(TObject *Sender)
{
    //��������� ������ ���������
	West_Level->Tag++;
}

//---------------------------------------------------------------------------

void __fastcall TWest_Form::ScoreTimerTimer(TObject *Sender)
{
    //����������� �����
	West_YourScore->Tag++;
	West_YourScore->Caption = IntToStr(West_YourScore->Tag);
}

//---------------------------------------------------------------------------

void __fastcall TWest_Form::EnemyTimerTimer(TObject *Sender)
{
	TRect Overlay;

	//�������� �����
	if (Enemy->Left < Player->Left) Enemy->Left += West_Level->Tag;
	if (Enemy->Left > Player->Left) Enemy->Left -= West_Level->Tag;
	if (Enemy->Top < Player->Top) Enemy->Top += West_Level->Tag;
	if (Enemy->Top > Player->Top) Enemy->Top -= West_Level->Tag;

	//�������� �� ������������
	if (IntersectRect(Overlay, Player->BoundsRect, Enemy->BoundsRect))
	{
        //���������� ��������
		EnemyTimer->Enabled = false;
		LevelTimer->Enabled = false;
		ScoreTimer->Enabled = false;

        //��������� ���������
        Enemy->Left = 160;
		Enemy->Top = 285;

		Player->Left = 520;
		Player->Top = 285;

        //����� ����
		EndGame();
	}
}

//---------------------------------------------------------------------------

void __fastcall TWest_Form::FormShow(TObject *Sender)
{
	//���������
	West_YourScore->Caption = "0";
	Money->Caption = "0";

	//��������� ���������
	Enemy->Left = 160;
	Enemy->Top = 285;

	Player->Left = 520;
	Player->Top = 285;

	//���� ������� ������ "New Game"
	F = false;

    //�������� ������� ����������
	TStringList *BestScoreList = new TStringList();
	BestScoreList->LoadFromFile("West\\WestBestScore.txt");

	AnsiString Name, TempName = "", buf, score = "";
	int i, j;
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

    //���������� ���
	BestScore->Caption = score;
}

//---------------------------------------------------------------------------

void __fastcall TWest_Form::West_NewGameClick(TObject *Sender)
{
    //���� ������� ������ "New Game"
	F = true;

    //��������� ���������
	Enemy->Left = 160;
	Enemy->Top = 285;

	Player->Left = 520;
	Player->Top = 285;

    //���������
	West_YourScore->Caption = "0";
	West_YourScore->Tag = 0;
	West_Level->Tag = 1;

	//��������� ��������
	EnemyTimer->Enabled = true;
	LevelTimer->Enabled = true;
	ScoreTimer->Enabled = true;
}

//---------------------------------------------------------------------------

void __fastcall TWest_Form::West_CancelClick(TObject *Sender)
{
    //���������� ��������
    EnemyTimer->Enabled = false;
	LevelTimer->Enabled = false;
	ScoreTimer->Enabled = false;

	AnsiString buf1 = Money->Caption, buf2 = "", buf3 = "";
	int i = 1, num;

	//��������� ����� ������
	buf2 = MainForm->Money2->Caption;

	//������� ����� � �������������� ������
	num = StrToInt(buf1) + StrToInt(buf2);
	if (num >= 99) num = 99;
	MainForm->Money2->Caption = IntToStr(num);

	//��������� ���������� �������� (��������� ��. TMainForm::ResetClick)
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

    //������ ������� ����� � ����
	nameFF = "";
	name = MainForm->Player2->Caption;

	TStringList *BestScoreList = new TStringList();
	BestScoreList->LoadFromFile("West\\WestBestScore.txt");

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

	BestScoreList->SaveToFile("West\\WestBestScore.txt");

	//�����
	ModalResult = mrCancel;
}

//---------------------------------------------------------------------------
