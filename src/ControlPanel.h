/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <wx/wx.h>

class ControlPanel : public wxPanel {
    private:
        wxPanel *parent;
        bool start;
        wxSlider *windSpeedSlider;

        wxBoxSizer *BuildControlButtons();
        wxBoxSizer *BuildWindDirectionSelect();
        wxBoxSizer *BuildWindSpeedSlider();
        wxBoxSizer *BuildGenerateForestButton();

    public:
        enum {
            idButtonStart = 1000,
            idButtonReset,
            idSliderWindSpeed,
            idButtonGenerateForest
        };

        ControlPanel(wxPanel *parent);

        bool IsStart();

        // events
        void OnStart(wxCommandEvent &event);
        void OnReset(wxCommandEvent &event);
        void OnWindSpeedSlider(wxScrollEvent &event);
        void OnGenerateForest(wxCommandEvent &event);
};

#endif // CONTROLPANEL_H
