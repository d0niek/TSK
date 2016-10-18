#ifdef WX_PRECOMP
    #include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif  // __BORLANDC__

#include "./MainApp.h"
#include "./MainFrame.h"

IMPLEMENT_APP(MainApp);

bool MainApp::OnInit() {
    MainFrame* frame = new MainFrame("TSK 2016", wxDefaultPosition, wxSize(800, 450));
    frame->Show();
    return true;
}
