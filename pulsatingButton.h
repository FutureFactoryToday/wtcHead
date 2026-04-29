#ifndef PULSATING_BUTTON_H
#define PULSATING_BUTTON_H

#include <wx/wx.h>
#include <wx/timer.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

class PulsatingButton : public wxControl {
public:
    PulsatingButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxBitmap& bitmap,
                   const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);

private:
    void OnPaint(wxPaintEvent& event);
    void OnMouseDown(wxMouseEvent& event);
    void OnMouseUp(wxMouseEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnMouseLeave(wxMouseEvent& event);


    // Переопределение для корректного размещения в сайзерах
    wxSize DoGetBestSize() const override;
    wxString m_label;
    wxBitmap m_bitmap;
    float m_scale;        // Текущий коэффициент масштаба
    float m_targetScale;  // Целевой масштаб для анимации
    bool  m_isBouncing;   // Флаг фазы возврата (эффект мячика)
    wxTimer m_timer;
};

#endif // PULSATING_BUTTON_H
