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
#include <cstring>

#include <windows.h>
//---------------------------------------------------------------------------
// flickering may be expiriensed
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
    TLabel *PathLabel;
    TEdit *PathEdit;
    TButton *ReopenButton;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall ResizeTimerTimer(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
    void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
    void __fastcall ScrollTimerTimer(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ReopenButtonClick(TObject *Sender);

private:	// User declarations
    struct FileMapping {
        HANDLE hFile;
        HANDLE hMapping;
        size_t fsize;
        unsigned char* dataPtr;
    } mappedData;

    int sampling; // graph sampling
    float startGraphX, stopGraphX;
    float startGraphY, stopGraphY;

    float coefA;
    float coefB;
    float coefC;

    TBitmap *graphBack;

    void zoom(int direction);
    float drawingFunstion(float coefA, float coefB, float coefC, float t);
    int toScreen(float val, float start, float stop, int space);
    void draw(int width, int height);

    // reading date
    void openFile();
    void readCoefs();

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

