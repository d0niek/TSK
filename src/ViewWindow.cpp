/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "./ViewWindow.h"

#include <GL/glu.h>
#include "../MainFrame.h"

BEGIN_EVENT_TABLE(ViewWindow, wxGLCanvas)
        EVT_PAINT(ViewWindow::OnIdle)
        EVT_SIZE(ViewWindow::Resized)
END_EVENT_TABLE()

ViewWindow::ViewWindow(wxPanel *parent, int *args)
    : wxGLCanvas(parent, wxID_ANY, args, wxPoint(-1, -1), wxSize(-1, -1), wxFULL_REPAINT_ON_RESIZE) {

    this->parent = parent;

    glContext = new wxGLContext(this);

    // To avoid flashing on MSW
    SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    forestGenerator = new ForestGenerator(60, 90);
    forest = forestGenerator->Generate(GetWidth(), GetHeight());
}

ViewWindow::~ViewWindow() {
    delete glContext;
}

void ViewWindow::Resized(wxSizeEvent &evt) {
    forestGenerator->ResetCellPointAndSize(forest, GetWidth(), GetHeight());

    Refresh();
}

void ViewWindow::Update() {
    if (!IsStart()) {
        return;
    }
}

void ViewWindow::Render() {
    if (!IsShown()) {
        return;
    }

    wxGLCanvas::SetCurrent(*glContext);
    wxPaintDC(this);  // wxPaintDC only to be used in paint events. use wxClientDC to paint outside the paint event

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Prepare2DViewport(0, 0, GetWidth(), GetHeight());
    glLoadIdentity();

    for (auto cellIt = forest.vertices.begin(); cellIt != forest.vertices.end(); cellIt++) {
        cellIt->Render();
    }

    glFlush();
    SwapBuffers();
}

/**
 * Inits the OpenGL viewport for drawing in 2D.
 */
void ViewWindow::Prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black Background
    glEnable(GL_TEXTURE_2D);   // textures
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(topleft_x, topleft_y, bottomrigth_x - topleft_x, bottomrigth_y - topleft_y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(topleft_x, bottomrigth_x, bottomrigth_y, topleft_y);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

bool ViewWindow::IsStart() {
    MainFrame *mainFrame = reinterpret_cast<MainFrame *>(parent->GetParent());
    return mainFrame->GetControlPanel()->IsStart();
}

int ViewWindow::GetWidth() {
    return GetSize().x;
}

int ViewWindow::GetHeight() {
    return GetSize().y;
}

void ViewWindow::OnIdle(wxPaintEvent &event) {
    Update();
    Render();
}
