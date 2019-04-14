//
// Created by Savu Liviu Gabriel on 13.04.2019.
//

#include "obarray.h"

ObArray::ObArray(int dimens, int grows, int size) {
    this->size = size;
    this->grows = grows;
    this->dimens = dimens;
    if(dimens > 0) this->p = new Object*[dimens];
    else this->p = nullptr;
    for (auto i = 0; i < this->dimens; i ++) {
        this->p[i] = nullptr;
    }
}

ObArray::ObArray(const ObArray &ob) {
    this->size = ob.size;
    this->grows = ob.grows;
    this->dimens = ob.dimens;
    this->p = new Object*[this->dimens];
    unsigned i;

    for (i = 0; i < this->dimens; i ++) {
        this->p[i] = nullptr;
        this->insertAt(i, ob.p[i]);
    }
}


ObArray::~ObArray() {
    this->RemoveAll();
}

void ObArray::RemoveAll() {
    unsigned i;
    if (this->dimens > 0) {
        for (i = 0; i < this->dimens; i++) {
            delete this->p[i];
            this->p[i] = nullptr;
        }
        delete[] this->p;
        this->p = nullptr;
    }
    this->dimens = 0;
    this->size = 0;
    this->grows = 0;
}

int ObArray::getSize() {
    return this->size;
}

int ObArray::add(Object* x) {
    unsigned i = 0;
    while (this->p[i] != nullptr && i < this->dimens) {
        i ++;
    }
    if (i == this->dimens) return 0;
    this->p[i] = x;
    this->size += grows;
    return 1;
}

Object* ObArray::getAt(int i) {
    if (i >= this->dimens) return nullptr;
    return this->p[i];
}

void ObArray::display() {
    unsigned i;
    std::cout << this->dimens << std::endl;
    for (i = 0; i < this->dimens ; i ++) {
        std::cout << i << ": " << p[i] << std::endl;
    }
}

int ObArray::removeAt(int i) {
    if (i < this->dimens) {
        delete p[i];
        p[i] = nullptr;
        this->size -= grows;
        return 1;
    }
    return 0;
}

int ObArray::insertAt(int i, Object *x) {
    if (i < this->dimens) {
        if (this->p[i] != nullptr) delete this->p[i];
        this->p[i] = x;
        this->size += this->grows;
        return 1;
    }
    return 0;
}