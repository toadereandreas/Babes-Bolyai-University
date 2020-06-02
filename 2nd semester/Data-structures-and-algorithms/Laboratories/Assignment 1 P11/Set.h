#ifndef ASSIGNMENT_1_SET_H
#define ASSIGNMENT_1_SET_H
#pragma once
#include "IteratorSet.h"
typedef int TElem;

class Set {
    friend class SetIterator;
private:
    int maximum_size, current_size ;
    TElem *elements ;
public:
    // implicit constructor
    Set();

    // adds an element to the set
    // if the element was added, the operation returns true, otherwise (if the element was already in the set)
    // it returns false
    bool add(TElem e);

    // removes an element from the set
    // if the element was removed, it returns true, otherwise false
    bool remove(TElem e);

    // checks if an element is in the  set
    bool search(TElem elem) const;

    // returns the number of elements;
    int size() const;

    // returns the maximum capacity
    int capacity() const;

    // return value from a given position
    TElem get_element( int position ) const;

    // checks if the set is empty
    bool isEmpty() const;

    // prints the elements
    void print();

    // returns an iterator for the set
    IteratorSet iterator() const;

    // destructor
    ~Set();
};
#endif //ASSIGNMENT_1_SET_H