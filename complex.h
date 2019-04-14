//
// Created by Savu Liviu Gabriel on 13.04.2019.
//

#ifndef POO2_COMPLEX_H
#define POO2_COMPLEX_H

#include <iostream>
#include "object.h"

class Complex: public Object {
private:
    double a, b;
public:
    Complex(): a(0), b(0) {}

    Complex(double a, double b): a(a), b(b) {}

    Complex(const Complex &ob): a(ob.a), b(ob.b) {}

    ~Complex() override;

    friend std::istream& operator >> (std::istream&, Complex&);

    friend std::ostream& operator << (std::ostream&, Complex&);

    Complex operator + (Complex const&);

    Complex operator * (Complex const&);

    void display() override;

    void setA(double);

    double getA();

    void setB(double);

    double getB();
};
#endif //POO2_COMPLEX_H
