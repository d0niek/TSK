/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <wx/wx.h>
#include "./Forest/Cell.h"
#include "./Forest/ForestGenerator.h"
#include "./Graph/Graph.h"

class ControlPanel : public wxPanel {
    private:
        wxPanel *parent;
        bool start;
        wxSlider *windSpeedSlider;
        ForestGenerator *forestGenerator;
        Graph<Cell, Empty> forest;

        wxBoxSizer *BuildControlButtons();
        wxBoxSizer *BuildWindDirectionSelect();
        wxBoxSizer *BuildWindSpeedSlider();
        wxBoxSizer *BuildGenerateForestButton();

        void GenerateForest();

    public:
        enum {
            idButtonStart = 1000,
            idButtonReset,
            idSliderWindSpeed,
            idButtonGenerateForest
        };

        ControlPanel(wxPanel *parent);

        bool IsStart();
        bool IsForestGenerated();
        void ResetForestCellsPointAndSize(float width, float height);

        // events
        void OnStart(wxCommandEvent &event);
        void OnReset(wxCommandEvent &event);
        void OnWindSpeedSlider(wxScrollEvent &event);
        void OnGenerateForest(wxCommandEvent &event);

        const Graph<Cell, Empty> &GetForest() const;
};

#endif // CONTROLPANEL_H
