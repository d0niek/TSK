/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <wx/wx.h>
#include <wx/glcanvas.h>
#include "./Forest/Cell.h"
#include "./Forest/ForestGenerator.h"
#include "./Graph/Graph.h"

class ViewWindow : public wxGLCanvas {
    private:
        wxPanel *parent;
        wxGLContext *glContext;
        ForestGenerator *forestGenerator;
        Graph<Cell, Empty> forest;

    public:
        ViewWindow(wxPanel *parent, int *args);
        virtual ~ViewWindow();

        void GenerateForest();
        bool IsForestGenerated();
        void BurnForest();
        void Update();
        void Render();
        void Prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);
        bool IsStart();
        int GetWidth();
        int GetHeight();

        // events
        void OnIdle(wxPaintEvent &event);
        void OnResize(wxSizeEvent &evt);

    DECLARE_EVENT_TABLE()
};

#endif // VIEWWINDOW_H
