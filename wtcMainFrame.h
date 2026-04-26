#ifndef WTC_MAIN_FRAME_H
#define WTC_MAIN_FRAME_H

#include <wx/wx.h>
#include "wtcTopBar.h"
#include "wtcInnerArea.h"
#include "wtcBottomBar.h"


class WtcMainFrame : public wxFrame
{
public:
	WtcMainFrame(wxFrame *frame, const wxString &title);
	~WtcMainFrame(){};
private:
	void OnClose(wxCloseEvent &event);
	void OnQuit(wxCommandEvent &event);
};

#endif // WTC_MAIN_FRAME_H