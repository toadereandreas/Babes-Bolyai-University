#include <iostream>
#include "Heap.h"

/* Subalgorithm add(heap, e) is:
 * // heap - a heap
 * // e - the element to be added
 * if heap.len = heap.cap then
 *      @ resize
 * end-if
 * heap.elements[heap.len+1] ← e
 * heap.len ← heap.len + 1
 * bubble-up(heap, heap.len)
 */
void Heap::add( TElem new_element ) {
    if( this->length == this->capacity )
        this->resize();
    this->elements[this->length+1] = new_element;
    this->length = this->length + 1;
    bubbleUp(this->length);
}

/* Subalgorithm bubble-up (heap, p) is:
 * // heap - a heap
 * // p - position from which we bubble the new node up
 * poz ← p
 * elem ← heap.elements[p]
 * parent ← p/2
 * while poz > 1 and elem > heap.elements[parent] execute
 *      //move parent down
 *      heap.elements[poz]←heap.elements[parent]
 *      poz ← parent
 *      parent ← poz/ 2
 * end-while
 * heap.elements[poz] ← elem
 *
 * Complexity : O(log2(n))
 */
void Heap::bubbleUp(int position) {
    int pos = position;
    TElem element = this->elements[position];
    int parent = position / 2 ;
    while( pos > 1 && element > this->elements[parent] ){
        this->elements[pos] = this->elements[parent];
        pos = parent;
        parent = pos/2;
    }
    this->elements[pos] = element;
}

/* Function remove(heap) is:
 * // Heap - is a heap
 * if heap.len = 0
 *      then @error - empty heap
 * end-if
 * deletedElem ← heap.elements[1]
 * heap.elements[1] ← heap.elements[heap.len]
 * heap.len ← heap.len - 1
 * bubble-down(heap, 1)
 * remove ← deletedElem
 * end-function
 */
TElem Heap::remove() {
    if( this->length == 0 )
        throw; // Empty heap => the root does not exists.
    TElem deleted_element = this->elements[1];
    this->elements[1] = this->elements[this->length];
    this->length = this->length - 1;
    bubbleDown(1);
    return deleted_element;
}

/* Subalgorithm bubbleDown(heap, p) is:
 * // heap - is a heap
 * // p - position from which we move down the element
 * poz ← p
 * elem ← heap.elements[p]
 * while poz < heap.len execute
 *      maxChild ← -1
 *      if poz * 2 ≤ heap.len then
 *      // It has a left child, assume it is the maximum
 *          maxChild ← poz * 2
 *      end-if
 *      if poz * 2 + 1 ≤ heap.len and heap.elements[2*poz+1] > heap.elements[2*poz] then
 *      // It has two children and the right is greater
 *          maxChild ← poz * 2 + 1
 *      end-if
 *      if maxChild != -1 and heap.elements[maxChild] > elem then
 *          tmp ← heap.elements[poz]
 *          heap.elements[poz] ← heap.elements[maxChild]
 *          heap.elements[maxChild]←tmp
 *          poz ← maxChild
 *      else
 *          poz ← heap.len + 1
 *          //to stop the while loop
 *      end-if
 *end-while
 *end-subalgorithm
 *
 * Complexity: O(log2(n))
 */
void Heap::bubbleDown(int position){
    int pos = position;
    TElem element = this->elements[position];
    while( pos < this->length ){
        int maxChild = -1;
        if( pos * 2 <= this->length )
            maxChild = pos * 2;
        if( pos * 2 + 1 <= this->length && this->elements[2*pos+1] > this->elements[2*pos] )
            maxChild = pos * 2 + 1;
        if( maxChild != -1 && this->elements[maxChild] > element ){
            TElem tmp = this->elements[pos];
            this->elements[pos] = this->elements[maxChild];
            this->elements[maxChild] = tmp;
            pos = maxChild;
        }
        else
            pos = this->length + 1;
    }
}

Heap::Heap(int capacity) {
    this->length = 0;
    this->capacity = capacity;
    this->elements = new TElem[capacity];
}

void Heap::print() {
    for( int i = 1 ; i <= this->length ; ++i )
        std::cout << this->elements[i] << ' ' ;
    std::cout << '\n';
}

void Heap::resize() {
    this->capacity = this->capacity * 2;
    TElem *aux = new TElem[capacity];
    for( int i = 0 ; i <= this->length ; ++i )
        aux[i] = this->elements[i];
    this->elements = aux;
}

int Heap::getSize() {
    return this->length;
}

Heap::~Heap() {
    delete [] this->elements;
}
