#ifdef WX_PRECOMP
    #include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif  // __BORLANDC__

#include "./MainFrame.h"

// helper functions
wxMenuBar* BuildMenuBar();
wxString GetBuildInfo();
// END helper functions

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_CLOSE(MainFrame::OnClose)
    EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {

    wxMenuBar* menuBar = BuildMenuBar();
    SetMenuBar(menuBar);

    CreateStatusBar(2);
    SetStatusText(_("Hello user!"), 0);
    SetStatusText(GetBuildInfo(), 1);
}

MainFrame::~MainFrame() {
}

void MainFrame::OnClose(wxCloseEvent &event) {
    Destroy();
}

void MainFrame::OnQuit(wxCommandEvent &event) {
    Destroy();
}

void MainFrame::OnAbout(wxCommandEvent &event) {
    wxString message;

    message << "Technologie Symulacji Komputerowych 2016.\n";
    message << "Symulacja pozaru lasu.\n\n";
    message << "Copyright Bogna Dudaczyk, Damian Glinkowski";

    wxMessageBox(
        message,
        _("Welcome to..."));
}

// helper functions
wxMenuBar* BuildMenuBar() {
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(wxID_EXIT, _("&Quit\tAlt-F4"), _("Quit the application"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(wxID_ABOUT, _("&About...\tF1"), _("Show info about this application"));

    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, _("&File"));
    menuBar->Append(helpMenu, _("&Help"));

    return menuBar;
}

wxString GetBuildInfo() {
    wxString wxbuild(wxVERSION_STRING);

#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif

    return wxbuild;
}
// END helper functions
