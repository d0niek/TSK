/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "./ControlPanel.h"
#include "../MainFrame.h"

ControlPanel::ControlPanel(wxPanel *parent)
    : wxPanel(parent, wxID_ANY) {

    this->parent = parent;
    start = false;

    wxBoxSizer *menuBox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *buttonsBox = BuildControlButtons();
    menuBox->Add(buttonsBox);

    wxBoxSizer *windSelectBox = BuildWindDirectionSelect();
    menuBox->Add(windSelectBox);

    wxBoxSizer *windSpeedBox = BuildWindSpeedSlider();
    menuBox->Add(windSpeedBox, 0, wxEXPAND);

    wxBoxSizer *generateForestButtonBox = BuildGenerateForestButton();
    menuBox->Add(generateForestButtonBox);

    SetSizer(menuBox);
}

wxBoxSizer *ControlPanel::BuildControlButtons() {
    wxBoxSizer *buttonsBox = new wxBoxSizer(wxHORIZONTAL);

    wxButton *startButton = new wxButton(this, idButtonStart, wxT("Start"));
    Connect(idButtonStart, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ControlPanel::OnStart));
    buttonsBox->Add(startButton, 0, wxALL, 10);

    wxButton *resetButton = new wxButton(this, idButtonReset, wxT("Reset"));
    Connect(idButtonReset, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ControlPanel::OnReset));
    buttonsBox->Add(resetButton, 0, wxTOP | wxRIGHT | wxBOTTOM, 10);

    return buttonsBox;
}

wxBoxSizer *ControlPanel::BuildWindDirectionSelect() {
    wxBoxSizer *windSelectBox = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *windDirectionsLabel = new wxStaticText(this, wxID_ANY, wxT("Wind direction:"));
    windSelectBox->Add(windDirectionsLabel, 0, wxALL, 10);

    wxArrayString windDirections;
    windDirections.Add(wxT("N"));
    windDirections.Add(wxT("NE"));
    windDirections.Add(wxT("E"));
    windDirections.Add(wxT("SE"));
    windDirections.Add(wxT("S"));
    windDirections.Add(wxT("SW"));
    windDirections.Add(wxT("W"));
    windDirections.Add(wxT("NW"));

    wxChoice *windChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, windDirections);
    windChoice->SetSelection(0);
    windSelectBox->Add(windChoice, 0, wxTOP | wxRIGHT | wxLEFT, 10);

    return windSelectBox;
}

wxBoxSizer *ControlPanel::BuildWindSpeedSlider() {
    wxBoxSizer *windSpeedBox = new wxBoxSizer(wxVERTICAL);

    wxStaticText *windSpeedLabel = new wxStaticText(this, wxID_ANY, wxT("Wind speed"));
    windSpeedBox->Add(windSpeedLabel, 0, wxALL, 10);

    windSpeedSlider = new wxSlider(
        this, idSliderWindSpeed, 2, 2, 8, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS | wxSL_TOP);
    Connect(idSliderWindSpeed, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(ControlPanel::OnWindSpeedSlider));
    windSpeedBox->Add(windSpeedSlider, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, 10);

    return windSpeedBox;
}

wxBoxSizer *ControlPanel::BuildGenerateForestButton() {
    wxBoxSizer *generateForestButtonBox = new wxBoxSizer(wxHORIZONTAL);

    wxButton *startButton = new wxButton(this, idButtonGenerateForest, wxT("Generate forest"));
    Connect(
        idButtonGenerateForest,
        wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(ControlPanel::OnGenerateForest)
    );
    generateForestButtonBox->Add(startButton, 0, wxALL, 10);

    return generateForestButtonBox;
}

bool ControlPanel::IsStart() {
    return start;
}

void ControlPanel::OnStart(wxCommandEvent &event) {
    start = true;

    MainFrame *mainFrame = reinterpret_cast<MainFrame *>(parent->GetParent());
    if (mainFrame->GetViewWindow()->IsForestGenerated()) {
        mainFrame->GetViewWindow()->BurnForest();
    }
}

void ControlPanel::OnReset(wxCommandEvent &event) {
    start = false;

    MainFrame *mainFrame = reinterpret_cast<MainFrame *>(parent->GetParent());
    if (mainFrame->GetViewWindow()->IsForestGenerated()) {
        mainFrame->GetViewWindow()->GenerateForest();
    }
}

void ControlPanel::OnWindSpeedSlider(wxScrollEvent &event) {
}

void ControlPanel::OnGenerateForest(wxCommandEvent &event) {
    MainFrame *mainFrame = reinterpret_cast<MainFrame *>(parent->GetParent());
    if (!IsStart()) {
        mainFrame->GetViewWindow()->GenerateForest();
    }
}
