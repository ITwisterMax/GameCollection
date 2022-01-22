//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "MainUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------





// +--------------+
// |              |
// | ������� ���� |
// |			  |
// +--------------+

bool Flag = False;
char GameArr[5] = { "" };

//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
	//�������� ��������
	Pages->ActivePage = Menu;
	//������������� �����
	GameExit->SetFocus();
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::LogInClick(TObject *Sender)
{
	//��������� ����� � ����������
	AccountForm->ShowModal();
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::PlayClick(TObject *Sender)
{
	if (Player1->Caption == "---") ShowMessage("Error! You need to log in...");
	else
	{
        //���������� ���������� ��������
		Player2->Caption = Player1->Caption;
		Money2->Caption = Money1->Caption;

		int i, j = 1;
		AnsiString tmp = Temp->Caption;

		for (i = 0; i < 5; i++)
		{
			GameArr[i] = tmp[j];
			j = j + 3;
		}

		//�������� ��������
		Pages->ActivePage = LoadGame;
	}
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::MusicClick(TObject *Sender)
{
	//������ ������������ ������
	if (not Flag)
	{
		MusicPlayer->Play();
		Music->Caption = "Music : on ";
		Flag = True;
	}
	else
	{
		MusicPlayer->Stop();
		Music->Caption = "Music : off ";
		Flag = False;
	}
}

void __fastcall TMainForm::MusicPlayerNotify(TObject *Sender)
{
	//���������� ������
	if (MusicPlayer->NotifyValue == nvSuccessful)
	{
		MusicPlayer->Notify = True;
		MusicPlayer->Play();
	}
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::GameExitClick(TObject *Sender)
{
	//�����
	MainForm->Close();
}

//---------------------------------------------------------------------------





// +------------+
// |            |
// | ����� ���� |
// |			|
// +------------+

//---------------------------------------------------------------------------

void __fastcall TMainForm::LoadGameShow(TObject *Sender)
{
	//������������� �����
	GoToMenu->SetFocus();

	//����������� ���������� �� �������� �����
	if (GameArr[0] == '1')
		IsOpen1->Picture->LoadFromFile("Menu\\V.png");
	else
		IsOpen1->Picture->LoadFromFile("Menu\\X.png");

	if (GameArr[1] == '1')
		IsOpen2->Picture->LoadFromFile("Menu\\V.png");
	else
		IsOpen2->Picture->LoadFromFile("Menu\\X.png");

	if (GameArr[2] == '1')
		IsOpen3->Picture->LoadFromFile("Menu\\V.png");
	else
		IsOpen3->Picture->LoadFromFile("Menu\\X.png");

	if (GameArr[3] == '1')
		IsOpen4->Picture->LoadFromFile("Menu\\V.png");
	else
		IsOpen4->Picture->LoadFromFile("Menu\\X.png");

	if (GameArr[4] == '1')
		IsOpen5->Picture->LoadFromFile("Menu\\V.png");
	else
		IsOpen5->Picture->LoadFromFile("Menu\\X.png");
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::ResetClick(TObject *Sender)
{
	int i, j;
	AnsiString buf1, buf2, nameFF = "", name = Player2->Caption;

	//�������� �� ��������� �������
	if (name == "Admin ")
	{
		ShowMessage("Error! You can't reset admin account...");
	}
	else
	{
		TStringList *List = new TStringList();
		List->LoadFromFile("Menu\\Info.txt");

		//��������� ����� ���������� �� ��������
		buf1 = name + "( 0 $ ) ( 1, 0, 0, 0, 0 )";

		//���� ������ ������
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
				//��������� ����������
				List->Strings[i] = buf1;
				break;
			}
		}

		//��������� � ����
		List->SaveToFile("Menu\\Info.txt");

		//��������� ������� ������� ���
		Temp->Caption = "1, 0, 0, 0, 0";
		GameArr[0] = '1';
		GameArr[1] = '0';
		GameArr[2] = '0';
		GameArr[3] = '0';
		GameArr[4] = '0';

		//��������� �������
		Money2->Caption = "0";
		Money1->Caption = Money2->Caption;

		//����������� �������� ���
		IsOpen1->Picture->LoadFromFile("Menu\\V.png");
		IsOpen2->Picture->LoadFromFile("Menu\\X.png");
		IsOpen3->Picture->LoadFromFile("Menu\\X.png");
		IsOpen4->Picture->LoadFromFile("Menu\\X.png");
		IsOpen5->Picture->LoadFromFile("Menu\\X.png");

        //��������, ���� �� ��� � ������ �������� ��� ���� "Point 15"
		TStringList *BestScore1 = new TStringList();

		BestScore1->LoadFromFile("Point15\\Point15BestScore.txt");

		buf2 = Player2->Caption;
		for (i = 0; i < BestScore1->Count; i++)
		{
			buf1 = BestScore1->Strings[i];

			j = 1;
			name = "";
			while (buf1[j] != ' ')
			{
				name = name + buf1[j];
				j++;
			}

			if (buf2 == name)
			{
				BestScore1->Delete(i);
				break;
			}
		}

		//���������� � ����
		BestScore1->SaveToFile("Point15\\Point15BestScore.txt");

		//��������, ���� �� ��� � ������ �������� ��� ���� "Wild West"
		TStringList *BestScore2 = new TStringList();

		BestScore2->LoadFromFile("West\\WestBestScore.txt");

		for (i = 0; i < BestScore2->Count; i++)
		{
			buf1 = BestScore2->Strings[i];

			j = 1;
			name = "";
			while (buf1[j] != ' ')
			{
				name = name + buf1[j];
				j++;
			}

			if (buf2 == name)
			{
				BestScore2->Delete(i);
				break;
			}
		}

		//���������� � ����
		BestScore2->SaveToFile("West\\WestBestScore.txt");
	}
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::GoToMenuClick(TObject *Sender)
{
	AnsiString buf = "";
	int i;

	//���������� ���������� �� ��������
	for (i = 0; i < 4; i++)
	{
		buf = buf + GameArr[i] + ", ";
	}
	buf = buf + GameArr[4];
	Temp->Caption = buf;

	Player1->Caption = Player2->Caption;
	Money1->Caption = Money2->Caption;

	//�������� ��������
	Pages->ActivePage = Menu;
}

//---------------------------------------------------------------------------





// +-------------+
// |             |
// | ������� ��� |
// |			 |
// +-------------+

//---------------------------------------------------------------------------

void __fastcall TMainForm::PingPongImageClick(TObject *Sender)
{
	//���������, ������� �� ����
	if (GameArr[0] == '1')
	{
		PingPong_Form->ShowModal();
	}
	else
	{
		//�������� ��
		if (MessageDlg("The game is closed. Do you want to buy it? (5 $)", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
			int i, j, num;
			AnsiString NewBalance = Money2->Caption;

			//���������� �� ����������
			num = StrToInt(NewBalance);
			if (num >= 5)
			{
				num = num - 5;
			}
			else
			{
				ShowMessage("Error! Not enough money...");
				goto Label;
			}

			//��������� ���������� �������� (��������� ��. TMainForm::ResetClick)
			Money2->Caption = IntToStr(num);
			Money1->Caption = Money2->Caption;

			AnsiString buf1, buf2, buf3 = "", nameFF = "", name = Player2->Caption;

			TStringList *List = new TStringList();
			List->LoadFromFile("Menu\\Info.txt");

			GameArr[0] = '1';
			IsOpen1->Picture->LoadFromFile("Menu\\V.png");
			for (i = 0; i < 4; i++)
			{
				buf3 = buf3 + GameArr[i] + ", ";
			}
			buf3 = buf3 + GameArr[4];

            Temp->Caption = buf3;
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
		}
	}
	Label : ;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::Point21ImageClick(TObject *Sender)
{
	//���������, ������� �� ����
	if (GameArr[1] == '1')
	{
		Point21_Form->ShowModal();
	}
	else
	{
		//�������� ��
		if (MessageDlg("The game is closed. Do you want to buy it? (10 $)", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
			int i, j, num;
			AnsiString NewBalance = Money2->Caption;

			//���������� �� ����������
			num = StrToInt(NewBalance);
			if (num >= 10)
			{
				num = num - 10;
			}
			else
			{
				ShowMessage("Error! Not enough money...");
				goto Label;
			}

			//��������� ���������� �������� (��������� ��. TMainForm::ResetClick)
			Money2->Caption = IntToStr(num);
			Money1->Caption = Money2->Caption;

			AnsiString buf1, buf2, buf3 = "", nameFF = "", name = Player2->Caption;

			TStringList *List = new TStringList();
			List->LoadFromFile("Menu\\Info.txt");

			GameArr[1] = '1';
			IsOpen2->Picture->LoadFromFile("Menu\\V.png");
			for (i = 0; i < 4; i++)
			{
				buf3 = buf3 + GameArr[i] + ", ";
			}
			buf3 = buf3 + GameArr[4];

			Temp->Caption = buf3;
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
		}
	}
	Label : ;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::TTTImageClick(TObject *Sender)
{
	//���������, ������� �� ����
	if (GameArr[2] == '1')
	{
		TTT_Form->ShowModal();
	}
	else
	{
		//�������� ��
		if (MessageDlg("The game is closed. Do you want to buy it? (15 $)", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
			int i, j, num;
			AnsiString NewBalance = Money2->Caption;

			//���������� �� ����������
			num = StrToInt(NewBalance);
			if (num >= 15)
			{
				num = num - 15;
			}
			else
			{
				ShowMessage("Error! Not enough money...");
				goto Label;
			}

			//��������� ���������� �������� (��������� ��. TMainForm::ResetClick)
			Money2->Caption = IntToStr(num);
			Money1->Caption = Money2->Caption;

			AnsiString buf1, buf2, buf3 = "", nameFF = "", name = Player2->Caption;

			TStringList *List = new TStringList();
			List->LoadFromFile("Menu\\Info.txt");

			GameArr[2] = '1';
			IsOpen3->Picture->LoadFromFile("Menu\\V.png");
			for (i = 0; i < 4; i++)
			{
				buf3 = buf3 + GameArr[i] + ", ";
			}
			buf3 = buf3 + GameArr[4];

            Temp->Caption = buf3;
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
		}
	}
	Label : ;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::Point15Click(TObject *Sender)
{
	//���������, ������� �� ����
	if (GameArr[3] == '1')
	{
		Point15_Form->ShowModal();
	}
	else
	{
		//�������� ��
		if (MessageDlg("The game is closed. Do you want to buy it? (20 $)", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
			int i, j, num;
			AnsiString NewBalance = Money2->Caption;

			//���������� �� ����������
			num = StrToInt(NewBalance);
			if (num >= 20)
			{
				num = num - 20;
			}
			else
			{
				ShowMessage("Error! Not enough money...");
				goto Label;
			}

			//��������� ���������� �������� (��������� ��. TMainForm::ResetClick)
			Money2->Caption = IntToStr(num);
			Money1->Caption = Money2->Caption;

			AnsiString buf1, buf2, buf3 = "", nameFF = "", name = Player2->Caption;

			TStringList *List = new TStringList();
			List->LoadFromFile("Menu\\Info.txt");

			GameArr[3] = '1';
			IsOpen4->Picture->LoadFromFile("Menu\\V.png");
			for (i = 0; i < 4; i++)
			{
				buf3 = buf3 + GameArr[i] + ", ";
			}
			buf3 = buf3 + GameArr[4];

            Temp->Caption = buf3;
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
		}
	}
	Label : ;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::WestImageClick(TObject *Sender)
{
	//���������, ������� �� ����
	if (GameArr[4] == '1')
	{
        West_Form->ShowModal();
	}
	else
	{
		//�������� ��
		if (MessageDlg("The game is closed. Do you want to buy it? (25 $)", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
			int i, j, num;
			AnsiString NewBalance = Money2->Caption;

			//���������� �� ����������
			num = StrToInt(NewBalance);
			if (num >= 25)
			{
				num = num - 25;
			}
			else
			{
				ShowMessage("Error! Not enough money...");
				goto Label;
			}

			//��������� ���������� �������� (��������� ��. TMainForm::ResetClick)
			Money2->Caption = IntToStr(num);
			Money1->Caption = Money2->Caption;

			AnsiString buf1, buf2, buf3 = "", nameFF = "", name = Player2->Caption;

			TStringList *List = new TStringList();
			List->LoadFromFile("Menu\\Info.txt");

			GameArr[4] = '1';
			IsOpen5->Picture->LoadFromFile("Menu\\V.png");
			for (i = 0; i < 4; i++)
			{
				buf3 = buf3 + GameArr[i] + ", ";
			}
			buf3 = buf3 + GameArr[4];

            Temp->Caption = buf3;
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
		}
	}
	Label : ;
}

//---------------------------------------------------------------------------
