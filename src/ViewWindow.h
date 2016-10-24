#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <wx/wx.h>
#include <wx/glcanvas.h>

class ViewWindow : public wxGLCanvas
{
    private:
        wxPanel *parent;
        wxGLContext *glContext;
        float angle;
        float rotateSpeed;

    public:
        ViewWindow(wxPanel *parent, int* args);
        virtual ~ViewWindow();

        void Resized(wxSizeEvent& evt);
        void Update();
        void Render();
        void Prepare3DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);
        void Prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);
        bool IsStart();
        int GetWidth();
        int GetHeight();
        void SetRotateSpeed(float rotateSpeed);

        // events
        // void OnIdle(wxIdleEvent &event);
        void OnIdle(wxPaintEvent &event);
        void OnMouseMoved(wxMouseEvent& event);
        void OnMouseDown(wxMouseEvent& event);
        void OnMouseWheelMoved(wxMouseEvent& event);
        void OnMouseReleased(wxMouseEvent& event);
        void OnRightClick(wxMouseEvent& event);
        void OnMouseLeftWindow(wxMouseEvent& event);
        void OnKeyPressed(wxKeyEvent& event);
        void OnKeyReleased(wxKeyEvent& event);

        DECLARE_EVENT_TABLE()
};

#endif // VIEWWINDOW_H
