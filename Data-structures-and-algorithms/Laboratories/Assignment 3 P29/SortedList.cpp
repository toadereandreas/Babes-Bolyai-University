#include <iostream>
#include "SortedList.h"
#include "Node.h"
#include "ListIterator.h"
SortedIndexedList::SortedIndexedList(Relation r) {
    this->head = NULL;
    this->tail = NULL;
    this->fct = r ;
};

int SortedIndexedList::size() const{
    Node *current ;
    current = head ;
    int size = 0 ;
    while( current != nullptr){
        ++size ;
        current = current->next ;
    }
    return size ;
}

void SortedIndexedList::print(){
    Node *current ;
    current = head ;
    while( current != nullptr){
        std::cout << current->value << ' ' ;
        current = current->next ;
    }
    std::cout << '\n' ;
}

bool SortedIndexedList::isEmpty() const{
    return head == NULL ;
};

bool SortedIndexedList::isPositionValid(int pos) const {
    if( pos < 0 || pos > size() - 1 )
        return false ;
    return true ;
}

TComp SortedIndexedList::getElement(int pos) const{
    if( pos < 0 || pos >= this->size() )
        throw("Invalid position");
    Node *current = head ;
    while( pos != 0 ){
        current = current->next ;
        --pos;
    }
    return current->value;
};

void SortedIndexedList::add(TComp e) {
    Node *new_node = new Node;
    new_node->value = e;
    new_node->prev = NULL ;
    new_node->next = NULL ;
    if( head == NULL )
        head = new_node ;
    else if( head->value >= new_node->value ){
        new_node->next = head ;
        new_node->next->prev = new_node ;
        head = new_node ;
    }
    else{
        Node *current = head;
        while( current->next != NULL && current->next->value < new_node->value )
            current = current->next ;
        new_node->next = current->next ;
        if( current->next != NULL )
            new_node->next->prev = new_node ;
        current->next = new_node ;
        new_node->prev = current ;
    }
    Node *current = head ;
    while( current->next != NULL )
        current = current->next;
    tail = current ;
    tail->next = NULL ;
    tail->prev = current->prev ;
}

TComp SortedIndexedList::remove( int pos ){
    if( pos < 0 )
        throw("Invalid position");
    if( pos == 0 ){
        TComp value = head->value ;
        head = head->next;
        return value ;
    }
    if( pos == size() - 1){
        TComp value = tail->value;
        tail = tail->prev ;
        return value ;
    }
    Node *current = head;
    while(pos > 0){
        if( current->next == NULL )
            throw("Invalid position");
        else {
            --pos;
            current = current->next;
        }
    }
    current->prev->next = current->next ;
    return current->value;
}

int SortedIndexedList::search(TComp e) const{
    Node *current = head;
    int position = 0 ;
    while( current != NULL){
        if( current->value == e ){
            return position;
        }
        ++position;
        current = current->next;
    }
    return -1;
}

ListIterator SortedIndexedList::iterator() const{
    return ListIterator(*this);
}