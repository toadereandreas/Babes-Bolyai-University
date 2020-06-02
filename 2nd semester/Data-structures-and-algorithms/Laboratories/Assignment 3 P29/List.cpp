#include "List.h"

void List::add( int new_value ){
    Node *new_node = new Node ;
    new_node->value = new_value ;
    new_node->next = NULL ;
    new_node->prev = NULL ;
    if( head== NULL ){
        head = new_node ;
        tail = new_node ;
        new_node = NULL ;
    }
    else{
        new_node->prev = tail ;
        tail->next = new_node ;
        tail = new_node ;
    }
}

void List::print_forward(){
    Node *current = new Node ;
    current = head ;
    while( current != NULL){
        std::cout << current->value << " " ;
        current = current->next ;
    }
    std::cout << '\n' ;
}

void List::print_backward(){
    Node *current = new Node ;
    current = tail ;
    while( current != NULL){
        std::cout << current->value << ' ' ;
        current = current->prev ;
    }
    std::cout << '\n' ;
}

int List::first(){
    return 1;
}

int List::last(){
    Node *current = new Node ;
    current = head ;
    int last = 0 ;
    while( current != NULL){
        ++last ;
        current = current->next ;
    }
    return last ;
}

bool List::valid( TPosition position ){
    return position < last();
}

TElem List::get_element( TPosition position){
    Node *current = new Node ;
    current = head ;
    while( current != NULL && position > -1 ){
        if( position )
            current = current->next ;
        --position;
    }
    return 0 ;
}