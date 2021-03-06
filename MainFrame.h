/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

#include "./MainApp.h"
#include "./src/RenderTimer.h"
#include "./src/ViewWindow.h"
#include "./src/ControlPanel.h"

class MainFrame : public wxFrame {
    private:
        RenderTimer *renderTimer;
        ViewWindow *viewWindow;
        ControlPanel *controlPanel;

        void BuildMenuBar();

    public:
        MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

        ViewWindow *GetViewWindow();
        ControlPanel *GetControlPanel();

        // events
        void OnQuit(wxCommandEvent &event);
        void OnAbout(wxCommandEvent &event);
};

#endif // MAINFRAME_H
