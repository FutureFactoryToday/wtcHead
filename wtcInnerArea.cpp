#include "wtcInnerArea.h"

WtcInnerArea::WtcInnerArea(wxWindow *parent, wxWindowID id, const wxDefaultPosition &pos, const wxDefaultSize &size, long style)
  : wxPanel(parent, id, pos, size, style)
{
  wxBoxSizer *backgroundSizer = new backgroundSizer(wxHORIZONTAL);
  this->SetBackgroundColour(wxColour(255, 255, 255));
  
  SetSizer(backgroundSizer);
}