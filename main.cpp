#include <wx/wx.h>       // Główne definicje wxWidgets
#include <wx/app.h>      // Dla klasy wxApp i makra wxIMPLEMENT_APP
#include <wx/frame.h>    // Dla klasy wxFrame, SetMenuBar, Close
#include <wx/menu.h>     // Dla klasy wxMenu i wxMenuBar
#include <wx/event.h>    // Dla Bind i wxCommandEvent
#include <wx/utils.h>
#include "MalpkaMyFrame.h"
#include <wx/image.h>

class MyApp : public wxApp {

public:

 virtual bool OnInit();
 virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() 
{
    wxImage::AddHandler(new wxPNGHandler); 
    wxImage::AddHandler(new wxJPEGHandler);
    
 //SetProcessDPIAware();
 wxFrame *mainFrame = new MalpkaMyFrame(NULL);
 mainFrame->Show(true);
 SetTopWindow(mainFrame);

 return true;
}
