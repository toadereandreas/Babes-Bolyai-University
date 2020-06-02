#ifndef ASSIGNMENT_6_P2_ITERATOR_H
#define ASSIGNMENT_6_P2_ITERATOR_H

#include <iostream>
#include "Hash.h"

class Iterator{
private:
    const Matrix &m;
    int pos;
public:
    Iterator(const Matrix &_m): m{_m} { this->pos = 0;}

    void first(){ this->pos = 0;}
    void next() { this->pos++;}
    bool valid(){ return this->pos >= 0 && pos < this->m.getM();}
    void getCurrent(){
        Triplet a = this->m.getFromPos(pos);
        while( a.getLine() == -1 || a.getColumn() == -1 )
        {
            ++pos;
            Triplet a = this->m.getFromPos(pos);
        }
        std::cout << "i = " << a.getLine() << ", j = " << a.getColumn() << ", value = " << a.getValue() << ".\n";
    }
};

#endif //ASSIGNMENT_6_P2_ITERATOR_H
