#ifndef LLA_IT_H
#define LLA_IT_H

#include "SLLA.h"

template <class U> class LLA;

template <class T>
class LLAIterator {
private:
    const LLA<T>& c;
    int it;
public:
    // Constructor
    // O(1)
    LLAIterator(const LLA<T>& list): c{list} {
        this->it = c.head;
    }

    // Iterates forward
    // O(1)
    void next() {
        if(!this->valid())
            throw std::exception();

        this->it = this->c.next[this->it];
    }

    void last(){
        int size = this->c.getSize() - 1;
        while(this->valid() && size != 0) {
            this->it = this->c.next[this->it];
            --size;
        }
    }

    // Sets the iterator to the first element
    void first() {
        this->it = this->c.head;
    }

    // Gets the current element
    // O(1)
    T getCurrent() const {
        if(!this->valid()) throw std::exception();

        return this->c.elems[this->it];
    }

    // Checks if it is valid
    // O(1)
    bool valid() const {
        return this->it != -1;
    }
};
#endif