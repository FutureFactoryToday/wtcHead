#ifndef WTC_TOP_BAR_H
#define WTC_TOP_BAR_H

#include <wx/wx.h>

class WtcTopBar : public wxPanel 
{
  WtcTopBar(wxWindow *parent, wxWindowID id, const wxDefaulPosition &pos, const wxDefaultSize &size, long style);
  ~WtcTopBar(){};
};
#endif //WTC_TOP_BAR_H