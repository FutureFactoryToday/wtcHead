#ifndef WTC_BOTTOM_BAR_H
#define WTC_BOOTOM_BAR_H

#include <wx/wx.h>

class WtcBottomBar : public wxPanel 
{
  WtcBottomBar(wxWindow *parent, wxWindowID id, const wxDefaulPosition &pos, const wxDefaultSize &size, long style);
  ~WtcBottomBar(){};
};
#endif //WTC_BOTTOM_BAR_H