///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/checkbox.h>
#include <wx/scrolbar.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel;
		wxButton* m_button_write;
		wxCheckBox* m_checkBox_banana;
		wxScrollBar* m_scrollBar;
		wxGauge* m_gauge;
		wxButton* m_button_color;
		wxTextCtrl* m_textCtrl;
		wxChoice* m_choice_figura;

		// Virtual event handlers, override them in your derived class
		virtual void m_panelOnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void m_panelOnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void m_button_writeOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox_bananaOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_scrollBarOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_button_colorOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choice_figuraOnChoice( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1051,653 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame();

};

