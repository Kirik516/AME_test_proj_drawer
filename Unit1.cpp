//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGraphView *GraphView;
//---------------------------------------------------------------------------
__fastcall TGraphView::TGraphView(TComponent* Owner)
    : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

