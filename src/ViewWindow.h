/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <wx/wx.h>
#include <wx/glcanvas.h>
#include "./Forest/Cell.h"
#include "./Forest/ForestGenerator.h"

class ViewWindow : public wxGLCanvas {
    private:
        wxPanel *parent;
        wxGLContext *glContext;
        float angle;
        float rotateSpeed;
        ForestGenerator *forestGenerator;
        std::vector<Cell> forest;

    public:
        ViewWindow(wxPanel *parent, int *args);
        virtual ~ViewWindow();

        void Resized(wxSizeEvent &evt);
        void Update();
        void Render();
        void Prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);
        bool IsStart();
        int GetWidth();
        int GetHeight();
        void SetRotateSpeed(float rotateSpeed);

        // events
        void OnIdle(wxPaintEvent &event);

    DECLARE_EVENT_TABLE()
};

#endif // VIEWWINDOW_H
