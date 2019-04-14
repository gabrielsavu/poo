//
// Created by Savu Liviu Gabriel on 13.04.2019.
//

#ifndef POO2_POINT_H
#define POO2_POINT_H
#include <iostream>
#include "object.h"

class Point: public Object {
private:
    double x, y;
public:
    Point(): x(0), y(0) {}

    Point(double x, double y): x(x), y(y) {}

    Point(const Point &ob): x(ob.x), y(ob.y) {}

    ~Point() override;

    friend std::istream& operator >> (std::istream&, Point&);

    friend std::ostream& operator << (std::ostream&, Point&);

    void display() override;

    void setX(double);

    double getX();

    void setY(double);

    double getY();
};

#endif //POO2_POINT_H
