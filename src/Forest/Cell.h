/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef CELL_H
#define CELL_H

#include <Windows.h>
#include <wx/string.h>
#include "../Util/Vector2f.h"
#include "../Util/Color.h"

class Cell {
    private:
        Vector2f point;
        float width;
        float height;
        Color color;

    public:
        Cell();
        Cell(Vector2f point, float width, float height, Color color);
        Cell(const Cell &cell);

        Cell &operator=(const Cell &cell);
        void Render();

        Vector2f GetPoint() const;
        void SetPoint(const Vector2f &color);
        float GetWidth() const;
        void SetWidth(float color);
        float GetHeight() const;
        void SetHeight(float color);
        Color GetColor() const;
        void SetColor(const Color &color);
};

wxString &operator<<(wxString &s, const Cell &cell);

#endif //CELL_H
