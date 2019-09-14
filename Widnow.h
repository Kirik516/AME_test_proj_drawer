//---------------------------------------------------------------------------

#ifndef WidnowH
#define WidnowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
#include <fstream>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TButton *ButtonRefresh;
    TLabel *GraphLabel;
    TLabel *LabelX;
    TLabel *LabelY;
    TGroupBox *GroupBox1;

private:	// User declarations
    int sampling; // graph sampling
    float startGraphX, stopGraphX;
    float startGraphY, stopGraphY;

    float coefA;
    float coefB;
    float coefC;

    TBitmap *graph;

    float drawingFunstion(float coefA, float coefB, float coefC, float t);
    int toScreen(float val, float start, float stop, int space);
    void draw(int width, int height);

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

