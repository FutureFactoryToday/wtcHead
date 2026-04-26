#include "wtcMainFrame.h"

WtcMainFrame::WtcMainFrame(wxFrame *frame, const wxString &title)
 : wxFrame(frame, title)
{
  SetMinSize(wxSize(1024,768));
 	SetMaxSize(wxSize(1024,768));
 	
 	wxBoxSizer *backgroundSizer = new wxBoxSizer(wxVERTICAL);
 	
 	WtcTopBar *topBar = new WtcTopBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
 	WtcInnerArea *innerArea = new WtcInnerArea(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
 	WtcBottomBar *bottomBar = new WtcBottomBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
 	
 	backgroundSizer->Add(topBar, 1, wxEXPAND|wxALL, 0);
 	backgroundSizer->Add(innerArea, 4, wxEXPAND|wxALL, 0);
 	backgroundSizer->Add(bottomBar, 1, wxEXPAND|wxALL, 0);
 	
 	SetSizer(backgroundSizer);
}
 
void WtcMainFrame::OnClose(wxCloseEvent &event)
{
  Destroy();
}

void WtcMainFrame::OnQuit(wxCommandEvent &event)
{
  Destroy();
}