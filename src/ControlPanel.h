#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <wx/wx.h>

class ControlPanel : public wxPanel
{
    private:
        wxPanel *parent;
        bool start;
        wxSlider* windSpeedSlider;

        wxBoxSizer *BuildControlButtons();
        wxBoxSizer *BuildWindDirectionSelect();
        wxBoxSizer *BuildWindSpeedSlider();

    public:
        enum {
            idButtonStart = 1000,
            idButtonReset,
            idSliderWindSpeed
        };

        ControlPanel(wxPanel *parent);

        bool IsStart();

        // events
        void OnStart(wxCommandEvent &event);
        void OnReset(wxCommandEvent &event);
        void OnWindSpeedSlider(wxScrollEvent &event);
};

#endif // CONTROLPANEL_H
