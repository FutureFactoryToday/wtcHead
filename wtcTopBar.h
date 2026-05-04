#ifndef WTC_TOP_BAR_H
#define WTC_TOP_BAR_H

#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include "blinkingButton.h"

class WtcTopBar : public wxPanel 
{
public:
  WtcTopBar(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style);
  ~WtcTopBar(){};
private:
  BlinkingButton *returnBtn;
  BlinkingButton *homeBtn;

  void OnButtonReturnClick(wxCommandEvent& event);
  void OnButtonHomeClick(wxCommandEvent& event);
};
#endif //WTC_TOP_BAR_H