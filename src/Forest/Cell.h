/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef CELL_H
#define CELL_H

#include <wx/string.h>
#include "../Util/Vector2f.h"
#include "../Util/Color.h"

class Cell {
    private:
        Vector2f point;
        float width;
        float height;
        Color color;

        /**
         * For Graph::bfs()
         */
        int t;
        int s;

    public:
        Cell();
        Cell(Vector2f point, float width, float height, Color color);

        void Render();

        Vector2f getPoint() const;
        void setPoint(const Vector2f &point);
        float getWidth() const;
        void setWidth(float width);
        float getHeight() const;
        void setHeight(float height);
        Color getColor() const;
        void setColor(Color color);

        int getT();
        void setT(int t);
        int getS();
        void setS(int s);
};

wxString &operator<<(wxString &s, const Cell &cell);

#endif //CELL_H
