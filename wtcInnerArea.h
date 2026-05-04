#ifndef WTC_INNER_AREA_H
#define WTC_INNER_AREA_H

#include <wx/wx.h>

class WtcInnerArea : public wxPanel 
{
public:
  WtcInnerArea(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style);
  ~WtcInnerArea(){};
};
#endif //WTC_INNER_AREA_H