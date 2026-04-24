#ifndef WTC_INNER_AREA_H
#define WTC_INNER_AREA_H

#include <wx/wx.h>

class WtcInnerArea : public wxPanel 
{
  WtcInnerArea(wxWindow *parent, wxWindowID id, const wxDefaulPosition &pos, const wxDefaultSize &size, long style);
  ~WtcInnerArea(){};
};
#endif //WTC_INNER_AREA_H