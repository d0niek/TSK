/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "./Color.h"

Color::Color()
    : r(0), g(0), b(0), a(1) {
}

Color::Color(float r, float g, float b)
    : r(r), g(g), b(b), a(1) {
}

Color::Color(float r, float g, float b, float a)
    : r(r), g(g), b(b), a(a) {
}

Color::Color(Vector3f vector)
    : r(vector.x), g(vector.y), b(vector.z), a(1) {
}

Color::Color(const Color &color)
    : r(color.r), g(color.g), b(color.b), a(color.a) {
}

Color &Color::operator=(const Color &color) {
    r = color.r;
    g = color.g;
    b = color.b;
    a = color.a;

    return *this;
}

bool Color::operator==(const Color &rhs) const {
    return r == rhs.r &&
           g == rhs.g &&
           b == rhs.b &&
           a == rhs.a;
}

bool Color::operator!=(const Color &rhs) const {
    return !(rhs == *this);
}

bool Color::operator<(const Color &rhs) const {
    if (r < rhs.r)
        return true;
    if (rhs.r < r)
        return false;
    if (g < rhs.g)
        return true;
    if (rhs.g < g)
        return false;
    if (b < rhs.b)
        return true;
    if (rhs.b < b)
        return false;
    return a < rhs.a;
}

bool Color::operator>(const Color &rhs) const {
    return rhs < *this;
}

bool Color::operator<=(const Color &rhs) const {
    return !(rhs < *this);
}

bool Color::operator>=(const Color &rhs) const {
    return !(*this < rhs);
}

wxString &operator<<(wxString &s, const Color &color) {
    s << "r:" << color.r << ", " << "g:" << color.g << ", " << "b:" << color.b << ", " << "a:" << color.a;

    return s;
}
