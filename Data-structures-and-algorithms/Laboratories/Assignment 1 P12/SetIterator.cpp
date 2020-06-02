// Created by Andreas on 4/7/2019.
#include "SetIterator.h"
#include "Set.h"

SetIterator::SetIterator( Set &c): con(c){
    this->first();
}

void SetIterator::first(){
    bool found = false;
    this->index = 0;
    while( !this->con.getElement(this->index) )
        ++this->index;
}

void SetIterator::next(){
    ++index;
}

bool SetIterator::valid(){
    if( this->index < 0 || this->index >= this->con.size() )
        return false;
    return true;
}

int SetIterator::getIndex(){
    return this->index;
}

int SetIterator::getCurrent(){
    return this->con.getElement(index);
}