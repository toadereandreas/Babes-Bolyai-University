#ifndef ASSIGNMENT_5_P8_HEAP_H
#define ASSIGNMENT_5_P8_HEAP_H

typedef int TElem;

class Heap{
    // Maxi-Heap with the starting index from 1 !!
private:
    int capacity;
    int length;
    TElem *elements;
public:
    // The constructor
    explicit Heap( int capacity );

    // The destructor
    ~Heap();

    /* Adds an element to the heap and puts it into the right place
     * Input : new_element - an element of type TElem
     * Preconditions : new_element is the element which will be added
     */
    void add( TElem new_element );

    /* After an element wad added to the last position of the heap,
     * bubbleUp moves it up the chain into its position
     * Input: position - an integer
     * Preconditions : position is the last element of the heap
     */
    void bubbleUp( int position );

    // Removes the root from the heap and puts the other elements into the right place
    TElem remove();

    /* After the root was removed, bubbleDown replaces it with the proper element
     * Input: position - an integer
     * Preconditions : position is the last element of the heap
     */
    void bubbleDown( int position );

    // Prints the heap
    void print();

    // Doubles the capacity of the elements
    void resize();

    /* Returns the size of the heap
     * Output : size - an integer
     * Postconditions : size is the number of elements in the heap
     */
    int getSize();
};

#endif //ASSIGNMENT_5_P8_HEAP_H
