/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "./Vector2f.h"

Vector2f::Vector2f()
    : x(0.0f), y(0.0f) {
}

Vector2f::Vector2f(float x, float y)
    : x(x), y(y) {
}

Vector2f::Vector2f(const Vector2f &vector)
    : x(vector.x), y(vector.y) {
}

Vector2f &Vector2f::operator=(const Vector2f &vector) {
    x = vector.x;
    y = vector.y;

    return *this;
}

bool Vector2f::operator==(const Vector2f &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Vector2f::operator!=(const Vector2f &rhs) const {
    return !(rhs == *this);
}

bool Vector2f::operator<(const Vector2f &rhs) const {
    if (x < rhs.x)
        return true;
    if (rhs.x < x)
        return false;
    return y < rhs.y;
}

bool Vector2f::operator>(const Vector2f &rhs) const {
    return rhs < *this;
}

bool Vector2f::operator<=(const Vector2f &rhs) const {
    return !(rhs < *this);
}

bool Vector2f::operator>=(const Vector2f &rhs) const {
    return !(*this < rhs);
}

wxString &operator<<(wxString &s, const Vector2f &vector) {
    s << "x:" << vector.x << ", " << "y:" << vector.y;

    return s;
}
