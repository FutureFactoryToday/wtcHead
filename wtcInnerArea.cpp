#include "wtcInnerArea.h"

WtcInnerArea::WtcInnerArea(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style)
  : wxPanel(parent, id, pos, size, style)
{
  wxBoxSizer *backgroundSizer = new wxBoxSizer(wxHORIZONTAL);
  this->SetBackgroundColour(wxColour(255, 255, 255));
  
  SetSizer(backgroundSizer);
}