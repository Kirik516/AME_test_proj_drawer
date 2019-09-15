//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Widnow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
    , sampling(1000)
    , startGraphX(-10.0)
    , stopGraphX(10.0)
    , startGraphY(-10.0)
    , stopGraphY(10.0)
    , coefA(0.0)
    , coefB(1.0)
    , coefC(1.0)
    , graphBack(new TBitmap)
{}
//---------------------------------------------------------------------------

void TForm1::zoom(int direction)
{
    if ( ((this->stopGraphX - direction) - (this->startGraphX + direction)) == 0
        || ((this->stopGraphY - direction) - (this->startGraphY + direction)) == 0)
    {
        return;
    }

    float fDirection = direction/4.0;
    this->startGraphX += fDirection;
    this->startGraphY += fDirection;
    this->stopGraphX -= fDirection;
    this->stopGraphY -= fDirection;

    // allows start redraw after scroll has been ended
    if (this->ScrollTimer->Enabled)
    {
        this->ScrollTimer->Enabled = false;
        this->ScrollTimer->Enabled = true;
        return;
    }

    this->ScrollTimer->Enabled = true;
}
//---------------------------------------------------------------------------

float TForm1::drawingFunstion(float coefA, float coefB, float coefC, float t)
{
    return coefA + coefB * std::sinf(coefC * t);
}
//---------------------------------------------------------------------------

int TForm1::toScreen(float val, float start, float stop, int space)
{
    float range = stop - start;
    float fInPx = range / space;
    return std::round((val - start) / fInPx);
}
//---------------------------------------------------------------------------

void TForm1::draw(int width, int height)
{
    this->graphBack->Width = width;
    this->graphBack->Height = height;
    TCanvas *canv = this->graphBack->Canvas;

    // beautiful border
    canv->Pen->Color = clSkyBlue;
    // trying some gray background color
    canv->Brush->Color = TColor(0x00404040);
    canv->Rectangle(0, 0, width, height);

    // drawing Axis
    canv->Pen->Color = clDkGray;
    // X
    canv->MoveTo(1, height/2);
    canv->LineTo(width - 3, height/2);
    // Y
    canv->MoveTo(width/2, 1);
    canv->LineTo(width/2, height - 3);

    // drawing graph
    canv->Pen->Color = clLime;
    canv->Pen->Width = 2;

    float h = (this->stopGraphX - this->startGraphX) / this->sampling;
    float px1 = this->startGraphX;
    float py1 = this->drawingFunstion(this->coefA, this->coefB, this->coefC,
                                                            this->startGraphX);
    float px2;
    float py2;

    for (int i = 0; i < this->sampling; i++)
    {
        px2 = px1 + h;
        py2 = this->drawingFunstion(this->coefA, this->coefB, this->coefC, px2);
        canv->MoveTo(this->toScreen(px1, this->startGraphX, this->stopGraphX, width),
                     this->toScreen(py1, this->startGraphY, this->stopGraphY, height));

        canv->LineTo(this->toScreen(px2, this->startGraphX, this->stopGraphX, width),
                     this->toScreen(py2, this->startGraphY, this->stopGraphY, height));
        px1 = px2;
        py1 = py2;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
    this->draw(this->GraphLabel->Width, this->GraphLabel->Height);
    this->GraphLabel->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    this->GraphLabel->Canvas->Draw(0, 0, this->graphBack);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResizeTimerTimer(TObject *Sender)
{
    this->ResizeTimer->Enabled = false;
    this->FormShow(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
    // allows start redraw after resize has been ended
    if (this->ResizeTimer->Enabled)
    {
        this->ResizeTimer->Enabled = false;
        this->ResizeTimer->Enabled = true;
        return;
    }

    this->ResizeTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
    this->zoom(-1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
    this->zoom(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScrollTimerTimer(TObject *Sender)
{
    this->ScrollTimer->Enabled = false;
    this->FormShow(NULL);
}
//---------------------------------------------------------------------------

