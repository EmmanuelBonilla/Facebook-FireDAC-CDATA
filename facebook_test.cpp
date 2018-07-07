//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <FireDAC.DApt.hpp>
#include "facebook_test.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FireDAC.Phys.CDataFacebook"
#pragma link "FireDAC.Phys.CDataFacebookDef"
#pragma resource "*.fmx"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TForm1::facebookConnectButtonClick(TObject *Sender)
{
	outputMemo -> Text = " ";

	try
	{
		FDConnection->Open();
		facebookExecute->Enabled = true;
        searchButton->Enabled = true;
		outputMemo->Lines->Add ("Connection established!");
	}

	catch (Exception& E)
	{
		outputMemo->Text = "Error: " + E.Message;
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::facebookExecuteButtonClick(TObject *Sender)
{
	int i;
	try
	{
		FDQuery1->SQL->Text = "SELECT * FROM Posts LIMIT 1";
		FDQuery1->Open();

		while (!FDQuery1->Eof)
		{
			for (i = 0; i < FDQuery1->FieldCount; i++) 
			{
				Db::TField* field = FDQuery1->Fields->Fields[i];
				String fieldValue = field->IsNull ? String("(null)") : field->AsString;
				outputMemo->Lines->Add(field->FieldName + " = " + fieldValue);
				//outputMemo->Lines->Add(field->AsString);
				//outputMemo->Lines->Add(field->DataSize);
			}
			outputMemo ->Lines ->Add("------");

			FDQuery1 ->Next();
		}
	}
	__finally
	{
		FDQuery1 ->Close();
	}
}



void __fastcall TForm1::searchButtonClick(TObject *Sender)
{
	int index;

	try
	{
		FDQuery1->SQL->Text = "SELECT * FROM users Limit 1";
		FDQuery1->Open();

		while (!FDQuery1->Eof)
		{
			for (index = 0; index < FDQuery1->FieldCount; index++)
			{
				Db::TField* field = FDQuery1->Fields->Fields[index];
				String fieldValue = field->IsNull ? String("(null)") : field->AsString;
				//outputMemo->Lines->Add(field->FieldName + " = " + fieldValue);
				outputMemo->Lines->Add(field->AsString);
				//outputMemo->Lines->Add(field->DataSize);
			}
			//outputMemo ->Lines ->Add("------");

			FDQuery1 ->Next();
		}
	}


	__finally
	{
        FDQuery1->Close();
    }
}
//---------------------------------------------------------------------------

