#ifndef WTC_BOTTOM_BAR_H
#define WTC_BOOTOM_BAR_H

#include <wx/wx.h>

class WtcBottomBar : public wxPanel 
{
public:
  WtcBottomBar(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style);
  ~WtcBottomBar(){};
};
#endif //WTC_BOTTOM_BAR_H