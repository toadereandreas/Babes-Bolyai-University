#ifndef LAB_1_SET_H
#define LAB_1_SET_H
#pragma once

#include "SetIterator.h"

typedef int TElem;

class Set {
    friend class SetIterator;
private:
    bool *Elems;
    int capacity;
    int mid_point;
public:
    // Implicit constructor
    Set();

    // Adds an element to the set.
    // If the element was added, the operation returns true,
    // otherwise (if the element was already in the set) it returns false
    bool add(TElem e);

    // Removes an element from the set.
    // If the element was removed, it returns true, otherwise false.
    bool remove(TElem e);

    // Checks if an element is in the set.
    bool search(TElem e) const;

    // Returns the number of elements.
    int size() const;

    // Checks if the set is empty.
    bool isEmpty() const;

    // Returns the element from a given position.
    TElem getElement(int position);

    // Returns an iterator for the set
    SetIterator iterator();

    //destructor
    ~Set();
};
#endif //LAB_1_SET_H