//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TGraphView : public TFrame
{
__published:	// IDE-managed Components
    TLabel *Graph;
    TLabel *LabelX;
    TLabel *LabelY;
    TLabel *LabelTitle;
private:	// User declarations
public:		// User declarations
    __fastcall TGraphView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGraphView *GraphView;
//---------------------------------------------------------------------------
#endif

