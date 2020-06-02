#ifndef ASSIGNMENT3_LIST_H
#define ASSIGNMENT3_LIST_H
#include "Node.h"
#include <iostream>
typedef int TPosition ;
typedef int TElem ;

class List{
private:
    Node *head, *tail;
public:
    List(){
        head = NULL ;
        tail = NULL ;
    }

    void List::add( int new_value );

    void List::print_forward();

    void List::print_backward();

    int first();

    int last();

    bool valid( TPosition position );

    TElem get_element( TPosition position);
    ~List(){};
};

#endif //ASSIGNMENT3_LIST_H
