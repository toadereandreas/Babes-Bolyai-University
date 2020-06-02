#include "ListIterator.h"
#include "SortedList.h"
ListIterator::ListIterator(const SortedIndexedList &c): con (c){
    this->position = 0;
}

void ListIterator::first() {
    this->position = 0;
}

TComp ListIterator::getCurrent() const {
    return this->con.getElement(position);
}

void ListIterator::next() {
    this->position++;
}

bool ListIterator::valid()  {
    if( this->position == this->con.size())
        return false;
    return true;
}