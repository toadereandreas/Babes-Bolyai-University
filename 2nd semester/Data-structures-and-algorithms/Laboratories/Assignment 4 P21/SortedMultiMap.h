#ifndef ASSIGNMENT_4_P21_SORTEDMULTIMAP_H
#define ASSIGNMENT_4_P21_SORTEDMULTIMAP_H
#pragma once

#include <vector>
#include <utility>
#include "SLLA.h"
#include "SMMIterator.h"

typedef int TKey;
typedef int TValue;
using namespace std;

typedef std::pair<TKey, TValue> TElem;
typedef bool(*Relation)(TKey, TKey);

typedef bool (*Condition)(TElem); // --------------- IN LAB ACTIVITY

class SortedMultiMap {
    friend class SMMIterator;
private:
    LLA<TElem> elems;
    bool (*fct)(TKey, TKey);
public:
    // Default constructor
    SortedMultiMap(Relation r);

    // Adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

    TElem getElement(int pos) const;

    TElem getPosition(TKey e) const;

    // Returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

    // Removes a key value pair from the sorted multimap
    // Returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    // Returns the number of key-value pairs from the sorted multimap
    int size() const;

    // Checks whether the given element exists in the LLA
    bool existsElement(TKey c, TValue v) const;

    // Verifies if the sorted multi map is empty
    bool isEmpty() const;

    // Returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)
    SMMIterator iterator() const;

    void print() const;

    // Keeps in the SMM only those pairs whose value respects the given condition.
    void filter(Condition cond);

    // Default destructor
    ~SortedMultiMap();
};

class SMMIterator{
private:
    const SortedMultiMap &smm;
    int index;
public:
    SMMIterator( const SortedMultiMap &smm_parameter): smm{smm_parameter}{
        index = 0;
    }

    void first(){
        index = 0;
    }

    TElem getCurrent(){
        if( valid() )
            return this->smm.getElement(index);
    }


    void next(){
        if( this->valid() )
            this->index++;
    }

    bool valid(){
        return index >= 0 && index < this->smm.size();
    }
};
#endif //ASSIGNMENT_4_P21_SORTEDMULTIMAP_H