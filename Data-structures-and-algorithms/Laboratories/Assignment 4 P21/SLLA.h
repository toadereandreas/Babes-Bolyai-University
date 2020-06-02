#ifndef LLA_H
#define LLA_H

#include <algorithm>
#include <exception>
#include <iostream>
#include "SLLA_iterator.h"

template <class U> class LLAIterator;
template <class T>
class LLA {
    template <class U> friend class LLAIterator;
private:
    int size;
    int capacity;
    T* elems;
    int* next;
    int* stack;
    int stackHead;
    int head;

    // Throws exception if <newCap> smaller than current number of elements
    // O(n) because container elements must be moved to new array
    void resize() {
        int newCap = this->capacity*2;
        T* auxElems = new T [newCap];
        int* auxNext = new int [newCap];
        int* auxStack = new int [newCap];

        std::copy(this->elems+0, this->elems+this->capacity, auxElems+0);
        std::copy(this->next+0, this->next+this->capacity, auxNext+0);
        for(int i = this->capacity; i < newCap; i++) {
            auxStack[++this->stackHead] = i;
        }

        delete[] this->elems;
        this->elems = auxElems;

        delete[] this->next;
        this->next = auxNext;

        delete[] this->stack;
        this->stack = auxStack;

        this->capacity = newCap;
    }

public:
    // Constructor
    // O(1)
    LLA() {
        this->capacity = 100;
        this->stackHead = -1;
        this->head = -1;
        this->size = 0;

        this->elems = new T [this->capacity];
        this->next = new int [this->capacity];
        this->stack = new int [this->capacity];

        for(int i = 0; i < this->capacity; i++) {
            this->stack[++stackHead] = i;
        }
    }

    // Searches an element
    // O(n) because it goes through the whole array
    bool search(T e) const {
        int current = this->head;
        while(current != -1 && this->elems[current] != e) {
            current = this->next[current];
        }

        return current != -1;
    }

    // Adds an element to the end.
    void addEnd(T e) {
        if(this->stackHead == -1)
            this->resize();

        if(this->head == -1) {
            this->addBegin(e);
            return;
        }

        int current = this->head;
        while(this->next[current] != -1)
            current = this->next[current];

        int freeIndex = this->stack[this->stackHead--];

        this->next[current] = freeIndex;
        this->next[freeIndex] = -1;
        this->elems[freeIndex] = e;
        this->size++;
    }

    // Adds an element to the beginning.
    void addBegin(T e) {
        if(this->stackHead == -1) this->resize();

        int freeIndex = this->stack[this->stackHead--];

        this->elems[freeIndex] = e;
        this->next[freeIndex] = this->head;
        this->head = freeIndex;
        this->size++;
    }

    // Adds an element before a given element.
    void addBefore(T compElem, T toInsert) {
        if(this->stackHead == -1)
            this->resize();

        if(this->elems[this->head] == compElem) {
            addBegin(toInsert);
            return;
        }

        int current = this->head;
        while(current != -1 && this->elems[this->next[current]] != compElem) {
            current = this->next[current];
        }

        int auxNext = this->next[current];
        int freeIndex = this->stack[this->stackHead--];

        this->next[current] = freeIndex;
        this->elems[this->next[current]] = toInsert;
        this->next[this->next[current]] = auxNext;
        this->size++;
    }

    // Delete element on given index
    // O(n)
    void remove(T e) {
        //if(!this->search(e)) // Check whether the given element exists
        //    throw std::exception();

        if(this->elems[this->head] == e) {
            this->stack[++this->stackHead] = this->head;
            this->head = this->next[this->head];
            this->size--;
            return;
        }

        int current = this->head;
        while(current != -1 && this->elems[this->next[current]] != e)
            current = this->next[current];

        this->stack[++this->stackHead] = this->next[current];
        this->next[current] = this->next[this->next[current]];
        this->size--;
    }

    // Return iterator
    // O(1)
    LLAIterator<T> getIterator() const {
        return LLAIterator<T>(*this);
    }

    // Get SLLA size
    // O(1)
    int getSize() const {
        return this->size;
    }

    // Destructor
    ~LLA() {
        delete[] this->elems;
        delete[] this->stack;
        delete[] this->next;
    }
};
#endif