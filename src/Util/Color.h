/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef COLOR_H
#define COLOR_H

#include <wx/string.h>
#include "./Vector3f.h"

struct Color {
    float r;
    float g;
    float b;
    float a;

    Color();
    Color(float r, float g, float b);
    Color(float r, float g, float b, float a);
    Color(Vector3f vector);
    Color(const Color &color);
    Color &operator=(const Color &color);

    Color operator+(const Color &color);
    Color &operator+=(const Color &color);
    bool operator==(const Color &rhs) const;
    bool operator!=(const Color &rhs) const;
    bool operator<(const Color &rhs) const;
    bool operator>(const Color &rhs) const;
    bool operator<=(const Color &rhs) const;
    bool operator>=(const Color &rhs) const;

};

wxString &operator<<(wxString &s, const Color &color);

#endif //COLOR_H
