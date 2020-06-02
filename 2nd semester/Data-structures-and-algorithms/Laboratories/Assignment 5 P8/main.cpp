#include <iostream>
#include "Heap.h"

int main() {
    Heap x(3);
    x.add(63);
    x.add(11);
    x.add(14);
    x.add(16);
    x.add(9);
    x.add(21);
    x.add(51);
    x.add(425);
    x.add(-572);
    x.add(525);
    x.add(-514);
    x.add(99);
    x.add(-231);
    x.add(-123);
    x.add(7);
    x.add(55);
    std::cout << "Size = " << x.getSize() << '\n' ;
    x.print();

    x.remove();
    std::cout << "Size = " << x.getSize() << '\n' ;
    x.print();

    x.remove();
    std::cout << "Size = " << x.getSize() << '\n' ;
    x.print();
    return 0;
}