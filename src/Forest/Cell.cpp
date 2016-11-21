/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "./Cell.h"

#include <GL/glu.h>

Cell::Cell()
    : point(Vector2f()), width(1.0f), height(1.0f), color(Color()) {
}

Cell::Cell(Vector2f point, float width, float height, Color color)
    : point(point), width(width), height(height), color(color) {
}

Cell::Cell(const Cell &cell)
    : point(cell.GetPoint()), width(cell.GetWidth()), height(cell.GetHeight()), color(cell.GetColor()) {
}

Cell &Cell::operator=(const Cell &cell) {
    point = cell.GetPoint();
    width = cell.GetWidth();
    height = cell.GetHeight();
    color = cell.GetColor();

    return *this;
}

void Cell::Render() const {
    glColor4f(color.r, color.g, color.b, color.a);

    glBegin(GL_QUADS);
        glVertex3f(point.x, point.y, 0);
        glVertex3f(point.x + width, point.y, 0);
        glVertex3f(point.x + width, point.y + height, 0);
        glVertex3f(point.x, point.y + height, 0);
    glEnd();
}

Vector2f Cell::GetPoint() const {
    return point;
}

void Cell::SetPoint(const Vector2f &point) {
    this->point = point;
}

float Cell::GetWidth() const {
    return width;
}

void Cell::SetWidth(float width) {
    this->width = width;
}

float Cell::GetHeight() const {
    return height;
}

void Cell::SetHeight(float height) {
    this->height = height;
}

Color Cell::GetColor() const {
    return color;
}

void Cell::SetColor(const Color &color) {
    this->color = color;
}

wxString &operator<<(wxString &s, const Cell &cell) {
    Color color = cell.GetColor();

    s << "Point " << cell.GetPoint() << "\n";
    s << "Width " << cell.GetWidth() << ", " << "Height " << cell.GetHeight() << "\n";
    s << "Color (rgba) ";
    s << color.r << ", " << color.g << ", " << color.b << color.a;

    return s;
}
