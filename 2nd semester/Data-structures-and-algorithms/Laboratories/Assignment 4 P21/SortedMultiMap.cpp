#include "SortedMultiMap.h"
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

SortedMultiMap::SortedMultiMap(Relation r) {
    this->fct = r;
}

void SortedMultiMap::add(TKey c, TValue v) {
    if( this->elems.getSize() == 0 )
        this->elems.addBegin(TElem(c, v));
    else {
        TElem position_element = this->getPosition(c);
        TElem new_element = TElem(c,v);
        auto last_element = this->elems.getIterator();
        last_element.last();
        if( last_element.getCurrent().first < c  )
            this->elems.addEnd(new_element);
        else
            this->elems.addBefore(position_element, new_element);
    }
}

vector<TValue> SortedMultiMap::search(TKey c) const {
    vector<TValue> elementList;
    auto it = this->elems.getIterator();
    it.first();
    while( it.valid() ){
        if( it.getCurrent().first == c )
            elementList.push_back(it.getCurrent().second);
        it.next();
    }
    return elementList;
}

int SortedMultiMap::size() const {
    return this->elems.getSize();
}

bool SortedMultiMap::isEmpty() const {
    return this->elems.getSize() == 0;
}

SortedMultiMap::~SortedMultiMap() {
}

void SortedMultiMap::print() const{
    auto it = this->elems.getIterator();
    it.first();
    while( it.valid() ){
        cout << it.getCurrent().first << ' ' << it.getCurrent().second << '\n' ;
        it.next();
    }
}

std::pair<TKey,TValue> SortedMultiMap::getPosition(TKey e) const{
    auto it = this->elems.getIterator();
    int times = 0;
    it.first();
    while( it.valid() ){
        ++times;
        if((this->fct(e,it.getCurrent().first)))
            return it.getCurrent();
        it.next();
    }
    it.first();
    while(it.valid() && times != 1 ) {
        --times;
        it.next();
    }
    return it.getCurrent();
}

bool SortedMultiMap::remove(TKey c, TValue v) {
    if( existsElement(c,v) ) {
        this->elems.remove(TElem(c, v));
        return true;
    }
    else
        return false;
}

bool SortedMultiMap::existsElement(TKey c,TValue v) const {
    auto it = this->elems.getIterator();
    while( it.valid() ){
        if( it.getCurrent().first == c && it.getCurrent().second == v )
            return true;
        it.next();
    }
    return false;
}

TElem SortedMultiMap::getElement(int pos) const {
    auto it = this->elems.getIterator();
    while( it.valid() ){
        if( pos == 0 )
            return TElem(it.getCurrent().first,it.getCurrent().second);
        it.next();
        pos--;
    }
}

SMMIterator SortedMultiMap::iterator() const {
    return SMMIterator(*this);
}

/* result
 * first is true
 * iterator = first element of smm.elems
 * while iterator is valid
 *      if condition of current
 *          if it is the first element
 *              result.add to beginning current
 *          else
 *              result.add to end current
 *      iterator <- next iterator
 * elements <- result
 *
 * Complexity: O(n)
 */
void SortedMultiMap::filter(Condition cond) {
    LLA<TElem> filtered_elements;
    bool first = true;
    auto it = this->elems.getIterator();
    while( it.valid()){ //iterating through all elements
        if( cond(it.getCurrent()) ) {
            // if the element fulfills the given condition
            if (first) {
                // if it is the first element I add it to the beginning
                filtered_elements.addBegin(it.getCurrent());
                first = false;
            }
            // otherwise I add it to the end ( to keep the initial order )
            else filtered_elements.addEnd(it.getCurrent());
        }
        it.next();
    }


    auto itr1 = this->elems.getIterator();
    while( itr1.valid()){
        // remove all the elements from the SMM
        this->elems.remove(itr1.getCurrent());
        itr1.next();
    }

    first = true;
    auto itr = filtered_elements.getIterator();
    while( itr.valid() ){
        // add the filtered elements back into the SMM, in the same order
        if( first ) {
            this->elems.addBegin(itr.getCurrent());
            first = false;
        }
        else
            this->elems.addEnd(itr.getCurrent());
        itr.next();
    }
    /*
    auto it = this->iterator();
    while(it.valid()){
        if( !cond(it.getCurrent()) )
            this->remove(it.getCurrent().first,it.getCurrent().second);
        it.next();
    }
     */
}
