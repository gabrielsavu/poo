#include <iostream>

class Object {
public:
    Object() {}
    virtual ~Object() {}
    virtual void display() = 0;
};

class ObArray : public Object {
private:
    Object **p;
    int size;
    int grows;
    int dimens;
public:
    ObArray(int, int, int);
    ~ObArray() override;
    void RemoveAll();
    int getSize();
    int add(Object*);
    int insertAt(int, Object*);
    int removeAt(int);
    Object* getAt(int);
    void display();
};

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
        this->size -= grows;
        return 1;
    }
    return 0;
}

int ObArray::insertAt(int i, Object *x) {
    if (i < this->dimens) {
        delete p[i];
        this->p[i] = x;
        this->size += this->grows;
        return 1;
    }
    return 0;
}

int ObArray::getSize() {
    return this->size;
}

ObArray::~ObArray() {
    this->RemoveAll();
}

void ObArray::RemoveAll() {
    unsigned i;
    for (i = 0; i < this->dimens; i ++) {
        delete this->p[i];
    }
    delete[] this->p;
}

ObArray::ObArray(int grows, int dimens, int size = 0) {
    this->size = size;
    this->grows = grows;
    this->dimens = dimens;
    this->p = new Object*[dimens];
    for (auto i = 0; i < this->dimens; i ++) {
        this->p[i] = nullptr;
    }
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

class Punct: public Object {
private:
    double x, y;
public:
    Punct(): x(0), y(0) {}

    void display() {
        std::cout << x << " " << y << std::endl;
    }

    void setX(double x) {
        this->x = x;
    }

    double getX() {
        return this->x;
    }

};



int main() {


    auto *p = new ObArray(1, 4);
    auto *temp = new Punct;
    temp->setX(4);
    p->add(temp);

    temp = new Punct;
    temp->setX(6);
    p->insertAt(3, temp);

    temp = new Punct;
    temp->setX(1);
    p->add(temp);

    p->display();

    std::cout << p->getSize();

    std::cout << ((Punct*)p->getAt(1))->getX();

    return 0;
}