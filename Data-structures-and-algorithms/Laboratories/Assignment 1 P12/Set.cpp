// Created by Andreas on 4/7/2019.
#include "Set.h"
typedef int TElem;

Set::Set(){
    this->capacity = 100000;
    this->mid_point = capacity/2;
    this->Elems = new bool[this->capacity];
    for( int i = 0 ; i < capacity ; ++i )
        this->Elems[i] = false;
}

bool Set::add(TElem e) {
    if( this->Elems[e+mid_point] || e+mid_point > 99999 || e+mid_point < 0)
        return false;
    else{
        this->Elems[e+mid_point] = true ;
        return true ;
    }
}

bool Set::remove(TElem e) {
    if( !this->Elems[e+mid_point] || e+mid_point > 99999 || e+mid_point < 0)
        return false;
    else{
        this->Elems[e+mid_point] = false ;
        return true ;
    }
}

bool Set::search(TElem e) const {
    if( e+mid_point < 0 || e+mid_point > 99999 )
        return false;
    return this->Elems[e+mid_point];
}

int Set::size() const {
    int size = 0;
    for( int i = 0 ; i <= 99999 ; ++i )
        if( this->Elems[i] )
            ++size;
    return size;
}

bool Set::isEmpty() const {
    return this->size() == 0;
}

SetIterator Set::iterator(){
    return SetIterator(*this);
}

Set::~Set() {
    delete [] this->Elems;
}

TElem Set::getElement(int position) {
    int index = 0;
    while(position>=0){
        if( this->Elems[index] )
            --position;
        ++index;
    }
    return index-this->mid_point-1;
}
