#ifndef ASSIGNMENT_4_P21_SMMITERATOR_H
#define ASSIGNMENT_4_P21_SMMITERATOR_H

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

#include "SortedMultiMap.h"
class SortedMultiMap;

/*
class SMMIterator{
private:
    SortedMultiMap &smm;
    int index;
public:
    SMMIterator(  SortedMultiMap &smm_parameter): smm{smm_parameter}{
        index = 0;
    }

    void first(){
        index = 0;
    }

    TElem getCurrent(){
        return this->smm.size();
    }

    /*
    bool valid(){
        return index >= 0 && index < this->smm.size();
    }
};*/
#endif //ASSIGNMENT_4_P21_SMMITERATOR_H