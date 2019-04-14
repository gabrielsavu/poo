//
// Created by Savu Liviu Gabriel on 13.04.2019.
//

#include "point.h"

Point::~Point() {
    x = 0;
    y = 0;
}

std::istream& operator >> (std::istream& in, Point& ob) {
    in >> ob.x;
    in >> ob.y;
    return in;
}

std::ostream& operator << (std::ostream& out, Point& ob) {
    out << "x = " << ob.x << " y = " << ob.y << std::endl;
    return out;
}

void Point::display() {
    std::cout << x << " " << y << std::endl;
}

void Point::setX(double x) {
    this->x = x;
}

double Point::getX() {
    return this->x;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::getY() {
    return this->y;
}
