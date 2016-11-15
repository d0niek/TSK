/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "Vector3f.h"

Vector3f::Vector3f()
    : x(0.0f), y(0.0f), z(0.0f) {
}

Vector3f::Vector3f(float x, float y, float z)
    : x(x), y(y), z(z) {
}

Vector3f::Vector3f(const Vector3f &vector)
    : x(vector.x), y(vector.y), z(vector.z) {
}

Vector3f &Vector3f::operator=(const Vector3f &rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

bool Vector3f::operator==(const Vector3f &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z;
}

bool Vector3f::operator!=(const Vector3f &rhs) const {
    return !(rhs == *this);
}

bool Vector3f::operator<(const Vector3f &rhs) const {
    if (x < rhs.x)
        return true;
    if (rhs.x < x)
        return false;
    if (y < rhs.y)
        return true;
    if (rhs.y < y)
        return false;
    return z < rhs.z;
}

bool Vector3f::operator>(const Vector3f &rhs) const {
    return rhs < *this;
}

bool Vector3f::operator<=(const Vector3f &rhs) const {
    return !(rhs < *this);
}

bool Vector3f::operator>=(const Vector3f &rhs) const {
    return !(*this < rhs);
}

wxString &operator<<(wxString &s, const Vector3f &vector) {
    s << "x:" << vector.x << ", " << "y:" << vector.y << ", " << "z:" << vector.z;

    return s;
}
