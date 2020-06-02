#include "SortedList.h"
#include <iostream>
#include <assert.h>

bool relation1(TComp e1, TComp e2) {
    if (e1 <= e2) {
        return true;
    }
    else {
        return false;
    }
}

void testAll();

int main() {

    SortedIndexedList x = SortedIndexedList(relation1);
    x.add(11);
    x.add(7);
    std::cout << x.size() << '\n';
    x.print();

    x.add(5);
    std::cout << x.size() << '\n';
    x.print();

    x.add(4);
    std::cout << x.size() << '\n';
    x.print();

    x.add(9);
    std::cout << x.size() << '\n';
    x.print();

    x.add(6);
    std::cout << x.size() << '\n';
    x.print();

    x.add(10);
    std::cout << x.size() << '\n';
    x.print();

    x.add(15);
    std::cout << x.size() << '\n';
    x.print();

    x.add(14);
    std::cout << x.size() << '\n';
    x.print();

    x.add(16);
    std::cout << x.size() << '\n';
    x.print();

    x.add(1);
    std::cout << x.size() << '\n';
    x.print();

    std::cout << "remove: " << x.remove(1) << '\n' ;
    std::cout << x.size() << '\n';
    x.print();

    std::cout << "remove: " << x.remove(0) << '\n' ;
    std::cout << x.size() << '\n';
    x.print();

    /*
    std::cout << "remove: " << x.remove(8) << '\n' ;
    std::cout << x.size() << '\n';
    x.print();
     */

    x.add(11);
    std::cout << x.size() << '\n';
    x.print();

    std::cout << "search 11: " << x.search(11) << '\n' ;
    std::cout << "search  5: " << x.search(5) << '\n' ;
    std::cout << "search 16: " << x.search(16) << '\n' ;
    std::cout << "search 99: " << x.search(99) << '\n' ;

    //std::cout << x.getElement(-1) ;
    //std::cout << " " << x.getElement(4) << " " << x.getElement(10) ;
    //ListIterator y = x.iterator();
    //y.first();

    std::cout << "\n-------\n";
    testAll();
    return 0;
}

void testAll(){
    SortedIndexedList list = SortedIndexedList(relation1);
    assert(list.size() == 0);
    assert(list.isEmpty());
    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());

    ListIterator iterator = list.iterator();
    assert(iterator.valid());
    iterator.first();
    assert(iterator.getCurrent() == 1);
    iterator.next();
    assert(!iterator.valid());
    iterator.first();
    assert(iterator.valid());

    assert(list.search(1) == 0);
    assert(list.remove(0) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());
}