#ifndef MAINFRAME_H
#define MAINFRAME_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "./MainApp.h"

class MainFrame: public wxFrame
{
    public:
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
        ~MainFrame();

    private:
        void OnClose(wxCloseEvent &event);
        void OnQuit(wxCommandEvent &event);
        void OnAbout(wxCommandEvent &event);

        DECLARE_EVENT_TABLE()
};

#endif // MAINFRAME_H
