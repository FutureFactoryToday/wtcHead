#ifndef BLINKING_BUTTON_H
#define BLINKING_BUTTON_H

#include <wx/wx.h>
#include <wx/timer.h>
#include <wx/artprov.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

class BlinkingButton : public wxControl 
{
public:
    BlinkingButton(wxWindow* parent, wxWindowID id, const wxBitmap& bitmap);

private:
    void OnPaint(wxPaintEvent& event);
    void OnLeftDown(wxMouseEvent& event);
    void OnLeftUp(wxMouseEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnSize(wxSizeEvent& event);

    wxBitmap m_bitmap;
    wxTimer m_timer;
    bool m_isPressed;
    double m_intensity; // Интенсивность градиента (0.0 - 1.0)
    bool m_increasing;  // Направление анимации
};

#endif //BLINKING_BUTTON_H