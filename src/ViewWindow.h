/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <wx/wx.h>
#include <wx/glcanvas.h>
#include "./Forest/Cell.h"
#include "./Graph/Graph.h"
#include "./Graph/Empty.h"

class ViewWindow : public wxGLCanvas {
    private:
        wxPanel *parent;
        wxGLContext *glContext;
        wxStopWatch watch;
        long time;
        const long deltaTime = 1000;
        int depth;

        bool IsStart();
        const Graph<Cell, Empty> &GetForest() const;
        void Prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);

    public:
        ViewWindow(wxPanel *parent, int *args);
        virtual ~ViewWindow();

        void Update();
        void Render();
        int GetWidth();
        int GetHeight();

        // events
        void OnIdle(wxPaintEvent &event);
        void OnResize(wxSizeEvent &evt);

    DECLARE_EVENT_TABLE()
};

#endif // VIEWWINDOW_H
