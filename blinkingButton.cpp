#include "blinkingButton.h"

BlinkingButton::BlinkingButton(wxWindow* parent, wxWindowID id, const wxBitmap& bitmap)
    : wxControl(parent, id),
      m_bitmap(bitmap),
      m_timer(this),
      m_isPressed(false),
      m_intensity(0.0),
      m_increasing(true) 
{
    SetBackgroundStyle(wxBG_STYLE_PAINT); // Предотвращает мерцание
    
    Bind(wxEVT_PAINT, &BlinkingButton::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &BlinkingButton::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &BlinkingButton::OnLeftUp, this);
    Bind(wxEVT_TIMER, &BlinkingButton::OnTimer, this);
    Bind(wxEVT_SIZE, &BlinkingButton::OnSize, this);
    
    SetInitialSize(wxSize(bitmap.GetWidth() + 10, bitmap.GetHeight() + 10));
}

void BlinkingButton::OnPaint(wxPaintEvent& event) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
    if (!gc) return;

    wxSize size = GetSize();
    double centerX = size.GetWidth() / 2.0;
    double centerY = size.GetHeight() / 2.0;
    double radius = wxMin(size.GetWidth(), size.GetHeight()) / 2.0;

    // 1. Рисуем градиент, если кнопка нажата
    if (m_isPressed) {
        wxColour color = wxColour(0, 120, 215, (unsigned char)(m_intensity * 180)); // Синий с прозрачностью
        wxGraphicsBrush gradient = gc->CreateRadialGradientBrush(
            centerX, centerY, centerX, centerY, radius, 
            color, wxColour(255, 255, 255, 0)
        );
        gc->SetBrush(gradient);
        gc->SetPen(*wxTRANSPARENT_PEN);
        gc->DrawEllipse(0, 0, size.GetWidth(), size.GetHeight());
    }

    // 2. Рисуем иконку (центрируем)
    double bmpX = centerX - (m_bitmap.GetWidth() / 2.0);
    double bmpY = centerY - (m_bitmap.GetHeight() / 2.0);
    gc->DrawBitmap(m_bitmap, bmpX, bmpY, m_bitmap.GetWidth(), m_bitmap.GetHeight());

    delete gc;
}

void BlinkingButton::OnLeftDown(wxMouseEvent& event) {
    m_isPressed = true;
    m_intensity = 0.2; // Начальная яркость
    m_increasing = true;
    m_timer.Start(50); // Скорость пульсации (мс)
    Refresh();
    CaptureMouse();
}

void BlinkingButton::OnLeftUp(wxMouseEvent& event) {
    if (m_isPressed) {
        m_isPressed = false;
        m_timer.Stop();
        if (HasCapture()) ReleaseMouse();
        Refresh();
        
        // Генерация события нажатия
        wxCommandEvent evt(wxEVT_BUTTON, GetId());
        evt.SetEventObject(this);
        ProcessWindowEvent(evt);
    }
}

void BlinkingButton::OnTimer(wxTimerEvent& event) {
    // Анимация пульсации
    if (m_increasing) {
        m_intensity += 0.05;
        if (m_intensity >= 0.8) m_increasing = false;
    } else {
        m_intensity -= 0.05;
        if (m_intensity <= 0.2) m_increasing = true;
    }
    Refresh();
}

void BlinkingButton::OnSize(wxSizeEvent& event) {
    Refresh();
    event.Skip();
}
