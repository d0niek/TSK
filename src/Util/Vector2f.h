/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <wx/string.h>

struct Vector2f {
    float x;
    float y;

    Vector2f();
    Vector2f(float x, float y);
    Vector2f(const Vector2f &vector);
    Vector2f &operator=(const Vector2f &vector);

    bool operator==(const Vector2f &rhs) const;
    bool operator!=(const Vector2f &rhs) const;
    bool operator<(const Vector2f &rhs) const;
    bool operator>(const Vector2f &rhs) const;
    bool operator<=(const Vector2f &rhs) const;
    bool operator>=(const Vector2f &rhs) const;
};

wxString &operator<<(wxString &s, const Vector2f &vector);

#endif //VECTOR2F_H
