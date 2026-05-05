#include <wx/wx.h>
#include "wtcMainFrame.h"


class WtcApp : public wxApp {
public:
	virtual bool OnInit() {
		//wxFrame *mainFrame = new wxFrame(NULL, wxID_ANY, wxT(""));
		WtcMainFrame *mainFrame = new WtcMainFrame(NULL, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxSTAY_ON_TOP|wxFRAME_SHAPED);
		mainFrame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(WtcApp);
