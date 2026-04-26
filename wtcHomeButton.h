#ifndef WTC_HOME_BUTTON_H
#define WTC_HOME_BUTTON_H

#include <wx/wx.h>

class WtcHomeButton : public wxControl
{
public:
	WtcHomeButton(wxWindow *parent, wxWindowID id, const wxDefaultPosition &pos, const wxDefaultSize &size, long style);
	~WtcHomeButton(){};
	
};

#endif // WTC_HOME_BUTTON_H