#include <iostream>
#include "Tests.h"
#include "Iterator.h"

int main() {

    test();
    Matrix m(5,5);
    m.modify(1,1,3);
   // Iterator i = m.iterator();
   // i.getCurrent();
    //std::cout << "Short tests passed !\n";

    /*
    Matrix m(5,5);
    std::cout << "Nr. of lines = " << m.nrLines() << ", nr. of columns = " << m.nrCols() << ".\n";

    std::cout << 1 << ' ' << 1 << ' ' << 5 << " after: \n";
    m.modify(1,1,5);
    m.print();

    std::cout << "\n\n\n";

    std::cout << 1 << ' ' << 1 << ' ' << 7 << " after: \n";
    m.modify(1,1,7);
    m.print();

    std::cout << "\n\n\n";

    std::cout << 3 << ' ' << 1 << ' ' << 8 << " after: \n";
    m.modify(3,1,8);
    m.print();

    std::cout << 2 << ' ' << 2 << ' ' << 9 << " after: \n";
    m.modify(2,2,9);
    m.print();

    std::cout << 2 << ' ' << 2 << ' ' << 13 << " after: \n";
    m.modify(2,2,13);
    m.print();

    std::cout << 2 << ' ' << 2 << ' ' << 0 << " after: \n";
    m.modify(4,2,15);
    m.print();

    std::cout << "\n Search (1,1) = " << m.element(1,1) << "\n";
    std::cout << "\n Search (3,1) = " << m.element(3,1) << "\n";
    std::cout << "\n Search (2,2) = " << m.element(2,2) << "\n";
    */
    return 0;
}