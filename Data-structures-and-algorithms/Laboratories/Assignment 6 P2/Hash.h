#include "Triplet.h"
//#include "Iterator.h"
#pragma once

class Iterator;

class Matrix {
    // class Iterator;

private:
    int numberOfLines;
    int numberOfColumns;

    Triplet *elements;
    int *next;
    int m;
    int firstFree;

    double alpha;

    int hash( Triplet element ) const { return ( element.getLine()*nrCols() + element.getColumn() ) % m;}

public:
    // Constructor
    // Throws exception if nrLines or nrCols is negative or zero
    Matrix(int nrLines, int nrCols);

    // Returns the number of lines
    // Complexity: Θ(1)
    int nrLines() const;

    // Returns the number of columns
    // Complexity: Θ(1)
    int nrCols() const;

    // Returns the element from line i and column j (indexing starts from 0)
    // Throws exception if (i,j) is not a valid position in the Matrix
    // Complexity: Θ(m) in worst case, but on average Θ(1)
    TElem element(int i, int j) const;

    // Finds the new firstFree position and updates firstFree
    // Complexity : O(m)
    void updateFirstFree();

    void updateAlpha();

    void resizeAndRehash();

    int getM() const;

    Triplet getFromPos(int idx) const;

    void print();

    // Modifies the value from line i and column j
    // Returns the previous value from the position
    // Throws exception if (i,j) is not a valid position in the Matrix
    // Complexity: Θ(m) in worst case, but on average Θ(1)
    TElem modify(int i, int j, TElem e);

   // Iterator iterator() const;
};