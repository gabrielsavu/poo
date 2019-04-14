#include <iostream>
#include "obarray.h"
#include "point.h"

int main() {
    unsigned n, i;
    double t1, t2;
    std::cout << "Elements:" << std::endl;
    std::cin >> n;
    auto *p = new ObArray(n);

    for(i = 0; i < n ; i ++) {
        std::cin >> t1 >> t2;
        p->add(new Point(t1, t2));
    }

    std::cout << "Remove:" << std::endl;
    std::cin >> i;
    if(p->removeAt(i)) std::cout << "Successfully Removed." << std::endl;
    else std::cout << "There was a problem removing element." << i << std::endl;

    std::cout << "Elements in vector: " << std::endl;

    p->display();
    std::cout << "Vector size:" << p->getSize() << std::endl;

    std::cout << "Elements in vector(cast): " << std::endl;
    for(i = 0; i < n ; i ++) {
        auto *ptr = dynamic_cast<Point*>(p->getAt(i));
        if (ptr != nullptr) std::cout << *ptr << std::endl;
    }

    return 0;
}