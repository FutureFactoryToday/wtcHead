#ifndef WTC_RETURN_BUTTON_H
#define WTC_RETURN_BUTTON_H

#include <wx/wx.h>

class WtcReturnButton : public wxControl
{
public:
	WtcReturnButton(wxWindow *parent, wxWindowID id, const wxDefaultPosition &pos, const wxDefaultSize &size, long style);
	~WtcReturnButton(){};
	
};

#endif // WTC_RETURN_BUTTON_H