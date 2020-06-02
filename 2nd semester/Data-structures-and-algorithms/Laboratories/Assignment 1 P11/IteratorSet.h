#ifndef ASSIGNMENT_1_ITERATORSET_H
#define ASSIGNMENT_1_ITERATORSET_H
typedef int TElem;
class Set;

class IteratorSet {
    friend class Set;

private:
        const Set &con;
        int current_position ;
public:
    // The constructor.
    IteratorSet(const Set &c);

    // This function returns the element of the iterator.
    TElem getCurrent();

    // This function checks whether the iterator is valid or not for "incrementation".
    bool valid() ;

    // This function checks whether the iterator is valid or not for "decrementation".
    bool valid_prev();

    // "Increments" the array
    void next();

    // "Decrements" the iterator
    void prev();

    // Sets the iterator to the first element.
    void first();

    // Sets the iterator to the last element.
    void last();
};
#endif //ASSIGNMENT_1_ITERATORSET_H
