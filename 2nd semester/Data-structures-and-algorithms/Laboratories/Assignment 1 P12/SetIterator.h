// Created by Andreas on 4/7/2019.
#ifndef LAB_1_SETITERATOR_H
#define LAB_1_SETITERATOR_H

typedef int TElem;
class Set;

class SetIterator{
    friend class Set;
private:
    Set &con;
    int index;
public:
    // The constructor.
    SetIterator( Set &c);

    // Sets the iterator to the first element.
    void first();

    // Sets the iterator to the next element.
    void next();

    // Gets the current element from the set.
    int getCurrent();

    // Checks whether the iterator is valid or not.
    bool valid();

    // Gets the index of the iterator.
    int getIndex();
};
#endif //LAB_1_SETITERATOR_H
