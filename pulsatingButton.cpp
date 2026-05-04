#include "pulsatingButton.h"

PulsatingButton::PulsatingButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxBitmap& bitmap, const wxPoint& pos, const wxSize& size)
    : wxControl(parent, id, pos, size),
      m_label(label), m_bitmap(bitmap), m_scale(1.0f), m_targetScale(1.0f), m_isBouncing(false)
{
    // Включаем двойную буферизацию для исключения мерцания
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    m_timer.SetOwner(this);
    
    Bind(wxEVT_PAINT, &PulsatingButton::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &PulsatingButton::OnMouseDown, this);
    Bind(wxEVT_LEFT_UP, &PulsatingButton::OnMouseUp, this);
    Bind(wxEVT_TIMER, &PulsatingButton::OnTimer, this, m_timer.GetId());
    Bind(wxEVT_SIZE, &PulsatingButton::OnSize, this);
    Bind(wxEVT_LEAVE_WINDOW, &PulsatingButton::OnMouseLeave, this);
}

void PulsatingButton::OnMouseDown(wxMouseEvent& event) {
    m_isBouncing = false;
    m_targetScale = 0.90f; // Уменьшение на 10%
    m_timer.Start(10);     // Интервал анимации (мс)
    CaptureMouse();
    Refresh();
}

void PulsatingButton::OnMouseUp(wxMouseEvent& event) {
    if (HasCapture()) ReleaseMouse();

    m_isBouncing = true;   // Включаем режим "прыжка"
    m_targetScale = 1.10f; // Увеличение на 10%
    m_timer.Start(10);

    // Генерируем стандартное событие нажатия кнопки
    wxCommandEvent evt(wxEVT_BUTTON, GetId());
    evt.SetEventObject(this);
    ProcessWindowEvent(evt);
}

void PulsatingButton::OnMouseLeave(wxMouseEvent& event) {
    if (!m_isBouncing && m_scale != 1.0f) {
        m_targetScale = 1.0f;
        m_timer.Start(10);
    }
}

void PulsatingButton::OnTimer(wxTimerEvent& event) {
    float step = 0.03f; // Скорость анимации

    if (std::abs(m_scale - m_targetScale) <= step) {
        m_scale = m_targetScale;
        
        if (m_isBouncing && m_targetScale > 1.0f) {
            // Если достигли пика "прыжка", возвращаемся к нормальному размеру
            m_targetScale = 1.0f;
        } else if (m_scale == 1.0f || m_targetScale == 0.90f) {
            m_timer.Stop();
        }
    } else {
        if (m_scale < m_targetScale) m_scale += step;
        else m_scale -= step;
    }
    Refresh();
}

void PulsatingButton::OnPaint(wxPaintEvent& event) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
    if (!gc) return;

    wxSize size = GetClientSize();
    double centerX = size.GetWidth() / 2.0;
    double centerY = size.GetHeight() / 2.0;

    // Сдвигаем систему координат в центр, масштабируем и сдвигаем обратно
    gc->PushState();
    gc->Translate(centerX, centerY);
    gc->Scale(m_scale, m_scale);
    gc->Translate(-centerX, -centerY);

    // Отрисовка Bitmap
    double bmpX = centerX - (m_bitmap.GetWidth() / 2.0);
    double bmpY = centerY - (m_bitmap.GetHeight() / 2.0);
    gc->DrawBitmap(m_bitmap, bmpX, bmpY, m_bitmap.GetWidth(), m_bitmap.GetHeight());

    // Отрисовка текста
    gc->SetFont(GetFont(), *wxWHITE);
    double tw, th;
    gc->GetTextExtent(m_label, &tw, &th);
    gc->DrawText(m_label, centerX - (tw / 2.0), centerY - (th / 2.0));

    gc->PopState();
    delete gc;
}

void PulsatingButton::OnSize(wxSizeEvent& event) {
    Refresh();
    event.Skip();
}

wxSize PulsatingButton::DoGetBestSize() const {
    // Рекомендуемый размер чуть больше картинки, чтобы было место для пульсации
    return wxSize(m_bitmap.GetWidth() * 1.2, m_bitmap.GetHeight() * 1.2);
}
