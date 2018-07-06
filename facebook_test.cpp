//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <FireDAC.DApt.hpp>
#include "facebook_test.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm1::connectButtonClick(TObject *Sender)
{
	outputMemo -> Text = " ";

	//Set the path of database file
	FDConnection1 -> DriverName = "SQLITE";
	FDConnection1 -> Params -> Values ["DataBase"] = "C:\\Users\\Public\\Documents\\Embarcadero\\Studio\\19.0\\Samples\\Data\\Employees.s3db";

	try //Establish Connection
	{
		FDConnection1 -> Open();
		executeButton -> Enabled = true;
		outputMemo -> Lines ->Add ("Connection established!");
	}
	catch (Exception& E)
	{
		outputMemo -> Text = "Exception raised with message" + E.Message;
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::executeButtonClick(TObject *Sender)
{
	TFDQuery *query;
	query = new TFDQuery (NULL);

	__try
	{
		query -> Connection = FDConnection1;

		//Define the SQL Query
		query -> SQL -> Text = "SELECT * FROM Employee";
		query -> Open();
		outputMemo -> Text = "";

		//Add the field names from table
		TVarRec args[3] = {"ID", "NAME", "DEPARTMENT"};
		outputMemo -> Lines -> Add (System::UnicodeString::
		Format ("|%8s |%25s |%25s |", args, ARRAYSIZE(args) -1));

		//Add one line to the memo for each record in the table
		while (!query -> Eof)
		{
			TVarRec arguments[3] = {query -> FieldByName ("ID") -> AsInteger,
									query->FieldByName ("Name") -> AsString, 
									query-> FieldByName ("Department") -> 
									AsString};
									
			outputMemo -> Lines -> Add (System::UnicodeString::
										Format("|%8d |%-25s |%-25s |", 
										arguments, ARRAYSIZE(arguments) -1));
			query -> Next();
		}
	}
	
	__finally
	{
		query -> Close();
		query -> DisposeOf();
    }
}
//---------------------------------------------------------------------------/---------------------------------------------------------------------------

