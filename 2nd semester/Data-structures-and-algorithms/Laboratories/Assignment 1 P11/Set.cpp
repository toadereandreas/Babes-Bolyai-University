// Created by User on 03/10/2019.
#include "Set.h"
#include "IteratorSet.h"
#include <iostream>

typedef int TElem;

Set::Set( ){
    this->current_size = 0 ;
    this->maximum_size = 10 ;
    this->elements = new TElem[this->maximum_size] ;
}

IteratorSet Set::iterator() const{
    return IteratorSet(*this);
}

TElem Set::get_element( int position) const{
    return this->elements[position] ;
}

bool Set::add(TElem e) {
    /* This function adds an element to the set.
     * Input : e, a TElem type of element
     * Output: true,  if the element was added to the set
     *         false, otherwise ( even if the element was already in the set )*/
    for (int i = 0; i < current_size; ++i)
        if( this->elements[i] == e )
            return false;
    if (current_size == maximum_size) {
        // If the set reaches its maximum capacity we double it.
        maximum_size *= 2;
        TElem *new_elements = new TElem[maximum_size];
        for (int i = 0; i < current_size; ++i)
            new_elements[i] = this->elements[i];
        delete []this->elements ;
        elements = new_elements ;
    }
    this->elements[this->current_size++] = e ;
    return true;
}

bool Set::remove(TElem e){
    /* This functions removes an element from the set.
     * Input : e, a TElem type of element
     * Output: true, if the element was removed
     *         false, otherwise */
    for( int i = 0 ; i < current_size ; ++i )
        if( elements[i] == e )
        {
            for( int j = i + 1 ; j < current_size ; ++j )
                elements[j-1] = elements[j] ;
            current_size -= 1 ;
            return true ;
        }
    return false ;
}

void Set::print(){
    for( int i = 0 ; i < current_size ; ++i )
        std::cout << elements[i] << " " ;
    std::cout << "\n" ;
}

bool Set::search(TElem e) const{
    /* This function searches for an element in the set.
     * Input : e, a TElem type of element
     * Output: true,  if the e element was found in the set
     *         false, if the e element was not found in the set */
    for( int i = 0 ; i < current_size ; ++i )
        if( elements[i] == e )
            return true ;
    return false ;
}

int Set::size() const{
    // This function returns the number of elements of the set.
    return current_size ;
}

int Set::capacity() const {
    // This function returns the maximum capacity of the set.
    return maximum_size ;
}

bool Set::isEmpty() const {
    // This function checks whether the set is empty or not.
    // Output : true,  if the set is empty
    //          false, if the set is not empty
    return current_size == 0 ;
}

Set::~Set(){
    delete[] this->elements ;
}