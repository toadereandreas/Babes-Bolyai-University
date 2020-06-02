#ifndef ASSIGNMENT3_LISTITERATOR_H
#define ASSIGNMENT3_LISTITERATOR_H

typedef int TComp;

class SorteIndexedList;

class ListIterator{
    friend class SortedIndexedList;
private:
    const SortedIndexedList &con;
    int position = 0;
public:
    ListIterator( const SortedIndexedList &c);
    void first();
    void next();
    bool valid() ;
    TComp getCurrent() const;
};

#endif //ASSIGNMENT3_LISTITERATOR_H
