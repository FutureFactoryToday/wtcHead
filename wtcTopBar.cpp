#include "wtcTopBar.h"

WtcTopBar::WtcTopBar(wxWindow *parent, wxWindowID id, const wxDefaultPosition &pos, const wxDefaultSize &size, long style)
  : wxPanel(parent, id, pos, size, style)
{
  wxBoxSizer *backgroundSizer = new backgroundSizer(wxHORIZONTAL);
  this->SetBackgroundColour(wxColour(0, 48, 78));
  
  wxButton *returnBtn = new wxButton(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
  wxStaticText *label = new wxStaticText(this, wxID_ANY, wxT("") wxDefaultPosition, wxDefaultSize);
  wxButton *homeBtn = new wxButton(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
  
  backgroundSizer->Add(returnBtn, 1, wxEXPAND|wxALL, 5);
  backgroundSizer->Add(label, 2, wxEXPAND|wxALL, 5);
  backgroundSizer->Add(homeBtn, 1, wxEXPAND|wxALL, 5);
  
  SetSizer(backgroundSizer);
}