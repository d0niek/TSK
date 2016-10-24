
#include "./MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {

    BuildMenuBar();

    wxPanel *mainPanel = new wxPanel(this, -1);
    wxBoxSizer *mainBox = new wxBoxSizer(wxHORIZONTAL);

    int args[] = { WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0 };
    viewWindow = new ViewWindow(mainPanel, args);
    mainBox->Add(viewWindow, 1, wxEXPAND);

    controlPanel = new ControlPanel(mainPanel);
    mainBox->Add(controlPanel);

    mainPanel->SetSizer(mainBox);

    renderTimer = new RenderTimer(viewWindow);
    renderTimer->start();

    Centre();
}

void MainFrame::BuildMenuBar() {
    wxMenuBar* menuBar = new wxMenuBar();

    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT, _("&Quit\tAlt-F4"), _("Quit the application"));
    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnQuit));
    menuBar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, _("&About...\tF1"), _("Show info about this application"));
    Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnAbout));
    menuBar->Append(helpMenu, _("&Help"));

    SetMenuBar(menuBar);
}

ViewWindow *MainFrame::GetViewWindow() {
    return viewWindow;
}

ControlPanel *MainFrame::GetControlPanel() {
    return controlPanel;
}

void MainFrame::OnQuit(wxCommandEvent &event) {
    Close(true);
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
