#ifndef ASSIGNMENT3_SORTEDLIST_H
#pragma once
#include "Node.h"
#include "ListIterator.h"

typedef int TComp;
typedef bool (*Relation)(TComp, TComp);

class SortedIndexedList {
    friend class ListIterator;
private:
    Node *head, *tail ;
    bool (*fct)( TComp, TComp);
public:
    // constructor
    SortedIndexedList(Relation r);

    // returns the size of the list
    int size() const;

    //checks if the list is empty
    bool isEmpty() const;

    // prints the list from left to right
    void print();

    // checks if the given position is valid
    bool isPositionValid(int pos) const;

    // returns an element from a position
    // throws exception if the position is not valid
    TComp getElement(int pos) const;

    // adds an element to a given position
    // throws an exception if the position is not valid
    void add(TComp e);

    // removes an element from a given position
    // returns the removed element
    // throws an exception if the position is not valid
    TComp remove(int pos);

    // searches for an element and returns the first position where the element appears or -1 if the element is not in the list
    int search(TComp e) const;

    // returns an iterator set to the first element of the list or invalid if the list is empty
    ListIterator iterator() const;

    //destructor
//    ~SortedIndexedList();
};
#define ASSIGNMENT3_SORTEDLIST_H
#endif //ASSIGNMENT3_SORTEDLIST_H
