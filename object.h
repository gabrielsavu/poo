//
// Created by Savu Liviu Gabriel on 13.04.2019.
//

#ifndef POO2_OBJECT_H
#define POO2_OBJECT_H

class Object {
public:
    Object() = default;
    virtual ~Object() = default;
    virtual void display() = 0;
};

#endif //POO2_OBJECT_H
