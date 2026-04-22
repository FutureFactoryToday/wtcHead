#include <wx/wx.h>

class WtcApp : public wxApp {
public:
	virtual bool OnInit() {
		wxFrame *mainFrame = new wxFrame(NULL, wxID_ANY, wxT(""));
		mainFrame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(WtcApp);
