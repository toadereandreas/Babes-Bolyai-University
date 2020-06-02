//
// Created by User on 03/10/2019.
//

#include "Set.h"
#include "IteratorSet.h"

IteratorSet::IteratorSet (const Set &c) : con(c) {
    this->current_position = 0 ;
}

TElem IteratorSet::getCurrent() {
    return this->con.get_element(current_position);
}

bool IteratorSet::valid() {
    if( this->current_position == this->con.size()  )
        return false ;
    return true ;
}

bool IteratorSet::valid_prev() {
    /* O(1)
     * if iterator position is less than 0
     *          the position is not valid
     * otherwise
     *          the position is valid
     */
    if( this->current_position >= 0 )
        return true ;
    return false ;
}

void IteratorSet::next() {
    if( this->valid() )
        this->current_position++;
}

void IteratorSet::prev(){
    /* O(1)
     * if the iterator decrementated is valid
     *          then we decrement the iterator
     * else
     *          an exception is thrown
     */
    if( this->valid_prev() )
        this->current_position-- ;
    else
        throw("Invalid iterator");
}

void IteratorSet::first(){
    this->current_position = 0 ;
}

void IteratorSet::last() {
    this->current_position = this->con.size() - 1;
}