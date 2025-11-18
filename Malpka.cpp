///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Malpka.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,500 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	wxBoxSizer* bSizer;
	bSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer2->Add( m_panel, 1, wxALL|wxEXPAND, 5 );


	bSizer->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	bSizer3->SetMinSize( wxSize( 250,-1 ) );
	m_button_write = new wxButton( this, wxID_ANY, _("Zapisz do pliku"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button_write, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_checkBox_banana = new wxCheckBox( this, wxID_ANY, _("Banana"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_checkBox_banana, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_scrollBar = new wxScrollBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL );
	m_scrollBar->SetMinSize( wxSize( 250,-1 ) );

	bSizer3->Add( m_scrollBar, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_gauge = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL|wxGA_SMOOTH );
	m_gauge->SetValue( 0 );
	m_gauge->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_gauge->SetMinSize( wxSize( 250,20 ) );
	m_gauge->SetMaxSize(wxSize(250,20));

	bSizer3->Add( m_gauge, 0, wxALL|wxEXPAND, 5 );

	m_button_color = new wxButton( this, wxID_ANY, _("Kolor gwiazdki"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button_color, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_textCtrl = new wxTextCtrl( this, wxID_ANY, _("Text"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_textCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	wxString m_choice_figuraChoices[] = { _("Gwiazdka"), _("Slonce"), _("Ksiezyc") };
	int m_choice_figuraNChoices = sizeof( m_choice_figuraChoices ) / sizeof( wxString );
	m_choice_figura = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_figuraNChoices, m_choice_figuraChoices, 0 );
	m_choice_figura->SetSelection( 0 );
	bSizer3->Add( m_choice_figura, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer->Add( bSizer3, 0, wxALL, 5 );


	this->SetSizer( bSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_panel->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::m_panelOnPaint ), NULL, this );
	m_panel->Connect( wxEVT_SIZE, wxSizeEventHandler( MyFrame::m_panelOnSize ), NULL, this );
	m_button_write->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_button_writeOnButtonClick ), NULL, this );
	m_checkBox_banana->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::m_checkBox_bananaOnCheckBox ), NULL, this );
	m_scrollBar->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::m_scrollBarOnScroll ), NULL, this );
	m_scrollBar->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::m_scrollBarOnScroll ), NULL, this );
	m_scrollBar->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::m_scrollBarOnScroll ), NULL, this );
	m_scrollBar->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::m_scrollBarOnScroll ), NULL, this );
	m_scrollBar->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::m_scrollBarOnScroll ), NULL, this );
	m_scrollBar->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::m_scrollBarOnScroll ), NULL, this );
	m_scrollBar->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::m_scrollBarOnScroll ), NULL, this );
	m_scrollBar->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::m_scrollBarOnScroll ), NULL, this );
	m_scrollBar->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::m_scrollBarOnScroll ), NULL, this );
	m_button_color->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_button_colorOnButtonClick ), NULL, this );
	m_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::m_textCtrlOnText ), NULL, this );
	m_choice_figura->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::m_choice_figuraOnChoice ), NULL, this );
}

MyFrame::~MyFrame()
{
}
