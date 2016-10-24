#ifndef RENDERTIMER_H
#define RENDERTIMER_H

#include <wx/timer.h>
#include "./ViewWindow.h"

class RenderTimer : public wxTimer
{
    private:
        ViewWindow *viewWindow;

    public:
        RenderTimer(ViewWindow *viewWindow);

        void Notify();
        void start();
};

#endif // RENDERTIMER_H
