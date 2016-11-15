/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <wx/string.h>

struct Vector3f {
    float x;
    float y;
    float z;

    Vector3f();
    Vector3f(float x, float y, float z);
    Vector3f(const Vector3f &vector);
    Vector3f &operator=(const Vector3f &rhs);

    bool operator==(const Vector3f &rhs) const;
    bool operator!=(const Vector3f &rhs) const;
    bool operator<(const Vector3f &rhs) const;
    bool operator>(const Vector3f &rhs) const;
    bool operator<=(const Vector3f &rhs) const;
    bool operator>=(const Vector3f &rhs) const;
};

wxString &operator<<(wxString &s, const Vector3f &vector);

#endif //VECTOR3F_H
