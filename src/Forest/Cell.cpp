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

void Cell::Render() {
    glColor4f(color.r, color.g, color.b, color.a);

    glBegin(GL_QUADS);
        glVertex3f(point.x, point.y, 0);
        glVertex3f(point.x + width, point.y, 0);
        glVertex3f(point.x + width, point.y + height, 0);
        glVertex3f(point.x, point.y + height, 0);
    glEnd();
}

Vector2f Cell::getPoint() const {
    return point;
}

void Cell::setPoint(const Vector2f &point) {
    Cell::point = point;
}

float Cell::getWidth() const {
    return width;
}

void Cell::setWidth(float width) {
    Cell::width = width;
}

float Cell::getHeight() const {
    return height;
}

void Cell::setHeight(float height) {
    Cell::height = height;
}

Color Cell::getColor() const {
    return color;
}

void Cell::setColor(Color color) {
    Cell::color = color;
}

int Cell::getT() {
    return t;
}

void Cell::setT(int t) {
    Cell::t = t;
}

int Cell::getS() {
    return s;
}

void Cell::setS(int s) {
    Cell::s = s;
}

wxString &operator<<(wxString &s, const Cell &cell) {
    s << "Point " << cell.getPoint() << "\n";
    s << "Width " << cell.getWidth() << ", " << "Height " << cell.getHeight() << "\n";
    s << "Color (rgba) ";
    s << cell.getColor().r << ", " << cell.getColor().g << ", " << cell.getColor().b << cell.getColor().a;

    return s;
}
