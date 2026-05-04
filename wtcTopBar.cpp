#include "wtcTopBar.h"

WtcTopBar::WtcTopBar(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style)
  : wxPanel(parent, id, pos, size, style)
{
  wxBoxSizer *backgroundSizer = new wxBoxSizer(wxHORIZONTAL);
  SetBackgroundColour(wxColour(0, 48, 78));
  
  wxString exeDir = wxFileName(wxStandardPaths::Get().GetExecutablePath()).GetPath();
  wxString resFolder = exeDir + "resources/"; // Сохранили общую часть

  wxString pathReturnIcon = resFolder + "returnIcon.png";
  wxString pathHomeIcon   = resFolder + "homeIcon.png";

  if(wxFileExists(pathReturnIcon)) 
  {
    wxBitmap returnIcon(pathReturnIcon, wxBITMAP_TYPE_PNG);
    returnBtn = new BlinkingButton(this, wxID_ANY, returnIcon);
  }
  else
  {
    wxBitmap placeholder = wxArtProvider::GetBitmap(wxART_QUESTION, wxART_BUTTON, wxSize(32, 32));
    returnBtn = new BlinkingButton(this, wxID_ANY, placeholder);
  }
  
    if(wxFileExists(pathHomeIcon)) 
  {
    wxBitmap homeIcon(pathHomeIcon, wxBITMAP_TYPE_PNG);
    homeBtn = new BlinkingButton(this, wxID_ANY, homeIcon);
  }
  else
  {
    wxBitmap placeholder = wxArtProvider::GetBitmap(wxART_QUESTION, wxART_BUTTON, wxSize(32, 32));
    homeBtn = new BlinkingButton(this, wxID_ANY, placeholder);
  }
  
  wxStaticText *label = new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
  
  backgroundSizer->Add(returnBtn, 1, wxEXPAND|wxALL, 5);
  backgroundSizer->Add(label, 2, wxEXPAND|wxALL, 5);
  backgroundSizer->Add(homeBtn, 1, wxEXPAND|wxALL, 5);
  
  returnBtn->Bind(wxEVT_BUTTON, &WtcTopBar::OnButtonReturnClick, this);
  homeBtn->Bind(wxEVT_BUTTON, &WtcTopBar::OnButtonHomeClick, this);
  
  SetSizer(backgroundSizer);
}

 void WtcTopBar::OnButtonReturnClick(wxCommandEvent& event)
 {
   
 }
 
 void WtcTopBar::OnButtonHomeClick(wxCommandEvent& event)
 {
   
 }