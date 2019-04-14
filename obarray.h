//
// Created by Savu Liviu Gabriel on 13.04.2019.
//

#ifndef POO2_OBARRAY_H
#define POO2_OBARRAY_H

#include <iostream>
#include "object.h"

class ObArray : public Object {
private:
    Object **p;
    int size;
    int grows;
    int dimens;
public:
    ObArray(int, int = 1, int = 0);
    ObArray(const ObArray &ob);
    ~ObArray() override;
    void RemoveAll();
    int getSize();
    int add(Object*);
    int insertAt(int, Object*);
    int removeAt(int);
    Object* getAt(int);
    void display() override;
};

#endif //POO2_OBARRAY_H
