#ifdef WX_PRECOMP
    #include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif  // __BORLANDC__

#include "./MainFrame.h"

#define MENU_WIDTH 300

// helper functions
wxMenuBar* BuildMenuBar();
wxString GetBuildInfo();
// END helper functions

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_CLOSE(MainFrame::OnClose)
    EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
    EVT_BUTTON(idButtonStart, MainFrame::OnButtonStart)
    EVT_BUTTON(idButtonReset, MainFrame::OnButtonReset)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {

    menuPosX = size.GetWidth() - MENU_WIDTH;

    wxButton* buttonStart = new wxButton(this, idButtonStart, "Start");
    wxButton* buttonReset = new wxButton(this, idButtonReset, "Reset");
    int space = (MENU_WIDTH - buttonStart->GetSize().GetWidth() - buttonReset->GetSize().GetWidth()) / 3;
    buttonStart->SetPosition(wxPoint(menuPosX + space, 10));
    buttonReset->SetPosition(wxPoint(menuPosX + space + buttonStart->GetSize().GetWidth() + space, 10));

    wxArrayString winds;
    winds.Add("N");
    winds.Add("NE");
    winds.Add("E");
    winds.Add("SE");
    winds.Add("S");
    winds.Add("SW");
    winds.Add("W");
    winds.Add("NW");
    wxComboBox* combo = new wxComboBox(
        this,
        idSelectWind,
        "N",
        wxPoint(menuPosX, 50),
        wxDefaultSize,
        winds,
        wxCB_DROPDOWN);

    wxMenuBar* menuBar = BuildMenuBar();
    SetMenuBar(menuBar);

    CreateStatusBar(2);
    SetStatusText(_("Hello user"), 0);
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

void MainFrame::OnButtonStart(wxCommandEvent &event) {
}

void MainFrame::OnButtonReset(wxCommandEvent &event) {
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
