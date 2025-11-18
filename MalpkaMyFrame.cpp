#include "MalpkaMyFrame.h"

MalpkaMyFrame::MalpkaMyFrame( wxWindow* parent )
:
MyFrame( parent )
{
    this->SetMinSize( wxSize( 800, 500 ) );

    m_starColour = *wxBLACK;
    m_scrollBar->Enable(false);
    m_scrollBar->SetScrollbar(0, 0, 100, 10);

    wxImage bananImage;
    if (bananImage.LoadFile("banan.png", wxBITMAP_TYPE_PNG))
    {
        bananImage.Rescale(50, 50);
        m_bananaBitmap = wxBitmap(bananImage);
    }
}

void MalpkaMyFrame::m_panelOnPaint( wxPaintEvent& event )
{
wxPaintDC dc(m_panel);

wxSize size = m_panel->GetClientSize();

int x_center = size.GetWidth() / 2;
int y_center = size.GetHeight() / 2;
int delta_y = 50;

dc.SetDeviceOrigin(x_center, y_center - delta_y);

DrawMonkey(dc);

wxPoint symbolPos(-150, -100);
int sz = 50;
DrawGraphicSymbol(dc, symbolPos.x, symbolPos.y, sz);

DrawTextElements(dc);
}

void MalpkaMyFrame::m_panelOnSize( wxSizeEvent& event )
{
m_panel->Refresh();
event.Skip();
}

void MalpkaMyFrame::m_button_writeOnButtonClick( wxCommandEvent& event )
{
    wxFileDialog saveFileDialog(this, 
                                _("Zapisz obrazek PNG"), "", "",
                                "Pliki PNG (*.png)|*.png",
                                wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_OK)
    {
        wxString path = saveFileDialog.GetPath();
        wxSize panelSize = m_panel->GetClientSize();
        
        wxBitmap bitmap(panelSize.GetWidth(), panelSize.GetHeight());
        wxMemoryDC memoryDC;
        memoryDC.SelectObject(bitmap);
        
        memoryDC.SetBackground(m_panel->GetBackgroundColour());
        memoryDC.Clear();

        int x_center = panelSize.GetWidth() / 2;
        int y_center = panelSize.GetHeight() / 2;
        int delta_y = 50;
        memoryDC.SetDeviceOrigin(x_center, y_center - delta_y);

        DrawMonkey(memoryDC);
        
        wxPoint symbolPos(-150, -100);
        int sz = 50;
        DrawGraphicSymbol(memoryDC, symbolPos.x, symbolPos.y, sz);
        
        DrawTextElements(memoryDC);

        memoryDC.SelectObject(wxNullBitmap); 

        wxImage image = bitmap.ConvertToImage();
        
        if (image.IsOk()) 
        {
            if (image.SaveFile(path, wxBITMAP_TYPE_PNG))
            {
                wxMessageBox(_("Rysunek pomyslnie zapisano do pliku!"), _("Zapis zakonczony"), wxOK | wxICON_INFORMATION);
            }
            else
            {
                wxMessageBox(_("Błąd zapisu pliku."), _("Błąd"), wxOK | wxICON_ERROR);
            }
        } else {
             wxMessageBox(_("Błąd konwersji obrazu."), _("Błąd"), wxOK | wxICON_ERROR);
        }
    }
}

void MalpkaMyFrame::m_checkBox_bananaOnCheckBox( wxCommandEvent& event )
{
m_hasBanana = event.IsChecked();

m_scrollBar->Enable(m_hasBanana);

m_panel->Refresh();
}

void MalpkaMyFrame::m_scrollBarOnScroll( wxScrollEvent& event )
{
int scrollPos = m_scrollBar->GetThumbPosition();

const double START_ANGLE = 0.0;
const double END_ANGLE = 85.0;
const double RANGE = END_ANGLE - START_ANGLE;

m_bananaAngle = START_ANGLE + (scrollPos / 100.0) * RANGE;

m_gauge->SetValue(scrollPos);
m_panel->Refresh();
}

void MalpkaMyFrame::m_button_colorOnButtonClick( wxCommandEvent& event )
{
wxColourDialog colourDialog(this);

colourDialog.GetColourData().SetColour(m_starColour);

if (colourDialog.ShowModal() == wxID_OK) {
m_starColour = colourDialog.GetColourData().GetColour();
m_panel->Refresh();
}

}

void MalpkaMyFrame::m_textCtrlOnText( wxCommandEvent& event )
{
m_panel->Refresh();
}

void MalpkaMyFrame::m_choice_figuraOnChoice( wxCommandEvent& event )
{
m_panel->Refresh();
}


void MalpkaMyFrame::DrawStar(wxDC& dc, int x, int y, int size)
{
    const int NUM_POINTS = 10;
    wxPoint points[NUM_POINTS];

    int outerRadius = size;
    int innerRadius = (int)(size / 2.5); 

    double angleOffset = -M_PI / 2.0; 

    for (int i = 0; i < NUM_POINTS; ++i)
    {
        double radius = (i % 2 == 0) ? outerRadius : innerRadius;
        double angle = angleOffset + i * (2.0 * M_PI / NUM_POINTS);

        points[i].x = x + (int)(radius * cos(angle));
        points[i].y = y + (int)(radius * sin(angle));
    }
    
    dc.SetPen(wxPen(m_starColour));
    dc.SetBrush(wxBrush(m_starColour));

    dc.DrawPolygon(NUM_POINTS, points);
}

void MalpkaMyFrame::DrawTextElements(wxDC& dc)
{
    wxString textToDraw = m_textCtrl->GetValue();

    if (textToDraw.IsEmpty()) {
        return;
    }

    wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    dc.SetFont(font);

    dc.SetTextForeground(*wxBLACK);

    dc.DrawText(textToDraw, -150, 200);

    wxFont font1(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    dc.SetFont(font1);

    int angle = 90; // Obrót o 90 stopni (w pionie)
    dc.DrawRotatedText(textToDraw, 200, 50, angle);

}

void MalpkaMyFrame::DrawSun(wxDC& dc, int x, int y, int size) 
{
    int radius = size;
    
    dc.SetPen(*wxYELLOW_PEN);
    dc.SetBrush(*wxYELLOW_BRUSH);

    dc.DrawCircle(x, y, radius);
}

void MalpkaMyFrame::DrawGraphicSymbol(wxDC& dc, int x, int y, int size)
{
    int selection = m_choice_figura->GetSelection();

    switch (selection) {
        case 0: 
            DrawStar(dc, x, y, size);
            break;
        case 1:
            DrawSun(dc, x, y, size);
            break;
        case 2:
            DrawMoon(dc, x, y, size);
            break;
    }
}

void MalpkaMyFrame::DrawMonkey(wxDC& dc) 
{
    const int LINE_THICKNESS = 2; 
    wxPen thickPen(*wxBLACK, LINE_THICKNESS); 
    dc.SetPen(thickPen);

    // Wymiary pomocnicze
    const int BODY_LEN = 150;
    const int ARM_SPAN = 40;
    const int HEAD_RAD = 30;
    const int HEAD_Y = -30;
    int Fx = 0;
    int Fy = -30;

    dc.DrawLine(0, 0, 0, BODY_LEN / 2);
    dc.DrawLine(0, BODY_LEN / 2, -25, BODY_LEN); 
    dc.DrawLine(0, BODY_LEN / 2, 25, BODY_LEN);
    dc.DrawLine(0, 0, 25, ARM_SPAN); // Lewa ręka 

    // Głowa i oczy
    dc.DrawCircle(0, -30, HEAD_RAD);
    dc.DrawCircle(-10, HEAD_Y - 5, 2);
    dc.DrawCircle( 10, HEAD_Y - 5, 2);

    const double BASE_ANGLE_RAD = 32.0 * M_PI / 180.0;
    double angleRad = BASE_ANGLE_RAD + (m_bananaAngle * M_PI / 180.0);
    double Py = (double)ARM_SPAN; 

    int x_end = (int)(0 - Py * sin(angleRad));
    int y_end = (int)(0 + Py * cos(angleRad)); 

    // Rysowanie obróconej łapki
    dc.DrawLine(0, 0, x_end - 3, y_end + 8);

    if (m_hasBanana)
    {
        // Radosna mina
        int mouthWidth = 16;
        int mouthHeight = 10;
        int mouthX = Fx - (mouthWidth / 2);
        int mouthY = Fy + 5; 
        dc.DrawEllipticArc(mouthX, mouthY - mouthHeight, mouthWidth, mouthHeight, 180, 360);

        if (m_bananaBitmap.GetWidth() > 0)
        {
            int bW = m_bananaBitmap.GetWidth();
            int bH = m_bananaBitmap.GetHeight();
            
            int bananaX = x_end - bW;
            int bananaY = y_end - bH / 2;
            
            dc.DrawBitmap(m_bananaBitmap, bananaX, bananaY, true); 
        }
    }
    else // Bez banana 
    {
        // Smutna mina
        int mouthWidth = 16;
        int mouthHeight = 10;
        int mouthX = Fx - (mouthWidth / 2);
        int mouthY = Fy + 5;           
        dc.DrawEllipticArc(mouthX, mouthY, mouthWidth, mouthHeight, 0,  180);
    }
}

void MalpkaMyFrame::DrawMoon(wxDC& dc, int x, int y, int size)
{
    int outerRadius = size;
    int innerRadius = (int)(size * 0.8); 
    int offset = (int)(outerRadius * 0.4); 
    
    wxColour bgColor = m_panel->GetBackgroundColour(); 
    
    wxColour moonColor(192, 192, 192);
    
    dc.SetPen(*wxBLACK_PEN);
    dc.SetBrush(wxBrush(moonColor)); 

    // Pierwsze koło (Księżyc)
    dc.DrawCircle(x, y, outerRadius);
    
    dc.SetPen(wxPen(bgColor, 1));
    dc.SetBrush(wxBrush(bgColor)); 

    // Drugie koło (Wycięcie)
    dc.DrawCircle(x + offset, y, innerRadius);
}