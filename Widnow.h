//---------------------------------------------------------------------------

#ifndef WidnowH
#define WidnowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
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
    TTimer *ResizeTimer;
    TTimer *ScrollTimer;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);

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

