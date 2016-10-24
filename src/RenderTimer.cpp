
#include "./RenderTimer.h"

RenderTimer::RenderTimer(ViewWindow *viewWindow)
    : wxTimer() {

    this->viewWindow = viewWindow;
}

void RenderTimer::Notify() {
    this->viewWindow->Refresh();
}

void RenderTimer::start() {
    wxTimer::Start(10);
}
