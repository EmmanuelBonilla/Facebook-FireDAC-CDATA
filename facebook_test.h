//---------------------------------------------------------------------------

#ifndef facebook_testH
#define facebook_testH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include "FireDAC.Phys.CDataFacebook.hpp"
#include "FireDAC.Phys.CDataFacebookDef.hpp"
#include <FMX.Edit.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *outputMemo;
	TFDPhysCDataFacebookDriverLink *FDPhysCDataFacebookDriverLink1;
	TFDConnection *FDConnection;
	TButton *facebookConnect;
	TButton *facebookExecute;
	TFDQuery *FDQuery1;
	TButton *searchButton;

	void __fastcall facebookConnectButtonClick(TObject *Sender);
	void __fastcall facebookExecuteButtonClick(TObject *Sender);
	void __fastcall searchButtonClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;

//---------------------------------------------------------------------------

#endif

