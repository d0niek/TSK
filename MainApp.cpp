#ifdef WX_PRECOMP
    #include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif  // __BORLANDC__

#include "./app.h"
#include "./main.h"

IMPLEMENT_APP(MainApp);

bool MainApp::OnInit() {
    MainFrame* frame = new MainFrame(0L, _("wxWidgets Application Template"));

    frame->Show();

    return true;
}
