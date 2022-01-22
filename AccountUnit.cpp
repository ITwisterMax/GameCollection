//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AccountUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TAccountForm *AccountForm;

//---------------------------------------------------------------------------

__fastcall TAccountForm::TAccountForm(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TAccountForm::FormShow(TObject *Sender)
{
	//������������� �����
	Cancel->SetFocus();
	//��������� ��������
	PlayerAccount->Items->LoadFromFile("Menu\\Info.txt");
	//����������� ���������
	PlayerAccount->ItemIndex = 0;
}

//---------------------------------------------------------------------------

void __fastcall TAccountForm::AddClick(TObject *Sender)
{
	//���� �����
	AnsiString result = InputBox("Add new account", "Enter name : ", "");
	result = Trim(result);

	if (result == "")
	{
		ShowMessage("Error! Enter correct name...");
	}
	else
	{
		//��������, ���� �� ��� � ������ ���������
		AnsiString buf, name;
		int i, j;

		for (i = 0; i < PlayerAccount->Count; i++)
		{
			buf = PlayerAccount->Items->Strings[i];

			j = 1;
			name = "";
			while (buf[j] != '(')
			{
				name = name + buf[j];
				j++;
			}

			if ((result + " ") == name)
			{
				ShowMessage("Error! Enter another name...");
				goto Label;
			}
		}

		//���������� ������ ��������
		result = result + " ( 0 $ ) ( 1, 0, 0, 0, 0 )";
		PlayerAccount->Items->Add(result);
	}

	Label : ;
	//����������� ���������
	PlayerAccount->ItemIndex = 0;
}

//---------------------------------------------------------------------------

void __fastcall TAccountForm::DeleteClick(TObject *Sender)
{
	//��������, �� ����������� �� ������� ���
	if ((PlayerAccount->ItemIndex != 0) && (PlayerAccount->ItemIndex != 1))
	{
        //��������, ���� �� ��� � ������ �������� ��� ���� "Point 15"
		TStringList *BestScore1 = new TStringList();
		AnsiString buf1, buf2 = "", name;
		int i, j;

		BestScore1->LoadFromFile("Point15\\Point15BestScore.txt");

		buf1 = PlayerAccount->Items->Strings[PlayerAccount->ItemIndex];
		j = 1;
		while (buf1[j] != ' ')
		{
			buf2 = buf2 + buf1[j];
			j++;
		}

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

		PlayerAccount->Items->Delete(PlayerAccount->ItemIndex);
	}
	else
	{
		ShowMessage("Error! You can't delete default/admin account...");
	}

	//����������� ���������
	PlayerAccount->ItemIndex = 0;
}

//---------------------------------------------------------------------------

void __fastcall TAccountForm::CancelClick(TObject *Sender)
{
	AnsiString name = "", balance = "", gamenum = "";
	AnsiString buf = PlayerAccount->Items->Strings[PlayerAccount->ItemIndex];
	int i = 1;

	//���������� � ����
	PlayerAccount->Items->SaveToFile("Menu\\Info.txt");

	//���������� �����
	while (buf[i] != '(')
	{
		name = name + buf[i];
		i++;
	}
	i = i + 2;
	MainForm->Player1->Caption = name;

	//���������� �������
	while (buf[i] != ' ')
	{
		balance = balance + buf[i];
		i++;
	}
	i = i + 7;
	MainForm->Money1->Caption = balance;

	//���������� �������� ���
	while (buf[i + 1] != ')')
	{
		gamenum = gamenum + buf[i];
		i++;
	}
	MainForm->Temp->Caption = gamenum;

    //�����
	ModalResult = mrCancel;
}

//---------------------------------------------------------------------------

