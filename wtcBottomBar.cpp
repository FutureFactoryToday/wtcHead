#include "wtcBottomBar.h"

WtcBottomBar::WtcBottomBar(wxWindow *parent, wxWindowID id, const wxDefaultPosition &pos, const wxDefaultSize &size, long style)
  : wxPanel(parent, id, pos, size, style)
{
  wxBoxSizer *backgroundSizer = new backgroundSizer(wxHORIZONTAL);
  this->SetBackgroundColour(wxColour(0, 116, 207));
  
  wxStaticText *remTimeLabel = new wxStaticText(this, wxID_ANY, wxT("") wxDefaultPosition, wxDefaultSize);
  wxStaticText *currentWaterLabel = new wxStaticText(this, wxID_ANY, wxT("") wxDefaultPosition, wxDefaultSize);
  wxStaticText *remWaterLabel = new wxStaticText(this, wxID_ANY, wxT("") wxDefaultPosition, wxDefaultSize);
  wxStaticText *timeLabel = new wxStaticText(this, wxID_ANY, wxT("") wxDefaultPosition, wxDefaultSize);
  
  backgroundSizer->Add(remTimeLabel, 1, wxEXPAND|wxALL, 5);
  backgroundSizer->Add(currentWaterLabel, 1, wxEXPAND|wxALL, 5);
  backgroundSizer->Add(remWaterLabel, 1, wxEXPAND|wxALL, 5);
  backgroundSizer->Add(timeLabel, 1, wxEXPAND|wxALL, 5);
  
  SetSizer(backgroundSizer);
}