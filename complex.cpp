//
// Created by Savu Liviu Gabriel on 13.04.2019.
//

#include "complex.h"

Complex::~Complex() {
    a = 0;
    b = 0;
}

std::istream& operator >> (std::istream& in, Complex& ob) {
    in >> ob.a;
    in >> ob.b;
    return in;
}

std::ostream& operator << (std::ostream& out, Complex& ob) {
    out << "z = " << ob.a << "+ " << ob.b << "i" << std::endl;
    return out;
}

Complex Complex::operator + (Complex const &ob) {
    Complex ret;
    ret.a = a + ob.a;
    ret.b = b + ob.b;
    return ret;
}

Complex Complex::operator * (Complex const &ob) {
    Complex ret;
    ret.a = a * ob.a - b * ob.b;
    ret.b = a * ob.b + b + ob.a;
    return ret;
}

void Complex::display() {
    std::cout << a << " " << b << std::endl;
}

void Complex::setA(double a) {
    this->a = a;
}

double Complex::getA() {
    return this->a;
}

void Complex::setB(double b) {
    this->b = b;
}

double Complex::getB() {
    return this->b;
}
