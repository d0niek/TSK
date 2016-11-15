
#include "./MainApp.h"
#include "./MainFrame.h"

IMPLEMENT_APP(MainApp);

bool MainApp::OnInit() {
    MainFrame *frame = new MainFrame("TSK 2016", wxDefaultPosition, wxSize(800, 450));
    frame->Show(true);

    return true;
}
