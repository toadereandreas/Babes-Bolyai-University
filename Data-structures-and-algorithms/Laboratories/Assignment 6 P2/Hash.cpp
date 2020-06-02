#include <iostream>
#include <exception>
#include "Hash.h"

Matrix::Matrix(int nrLines, int nrCols) {
    if( nrLines <= 0 || nrCols <= 0 )
        throw std::exception();
    else
    {
        // Initialize matrix
        this->numberOfLines = nrLines;
        this->numberOfColumns = nrCols;

        // Initialize hash
        this->m = 10; // The hash function will modulo the hashCode % m
        this->elements = new Triplet[m];
        this->next = new int[m];
        this->firstFree = 0;
        this->alpha = 0;

        for( int i = 0; i < m ; ++i ){
            this->elements[i].initialize();
            this->next[i] = -1;
        }
    }
}

int Matrix::nrLines() const {
    return this->numberOfLines;
}

int Matrix::nrCols() const {
    return this->numberOfColumns;
}

TElem Matrix::modify(int i, int j, TElem e) {
    // Complexity : Θ (m) in worst case, but on average Θ(1)
    // Validate i and j
    if( i < 0 || j < 0 || this->numberOfColumns <= i || this->numberOfLines <= j )
        throw std::exception();

    int currentValue = this->element(i,j); // Check whether an element on the given position already exists.

    if( currentValue == 0 && e != 0 ){
        // The element does not exist and the new one needs to be added.
        Triplet newTriplet(i,j,e);
        int position = this->hash(newTriplet);

        if( this->elements[position].getLine() == -1 && this->elements[position].getColumn() == -1 ){
            // The respective hash position is empty
            this->elements[position] = newTriplet;
            this->next[position] = -1;
        }
        else{

            if( this->firstFree == this->m )
                int x = 1; // RESIZE AND REHASH NEEDED --------------------------------
            int current = position;
            //std::cout << "current = " << current << '\n';
            while(this->next[current] != -1 )
                current = this->next[current];
            //std::cout << "current2 = " << current << '\n';
            //std::cout << "first free : " << this->firstFree << '\n';
            this->elements[this->firstFree] = newTriplet;
            this->next[this->firstFree] = -1;
            this->next[current] = this->firstFree;
            updateFirstFree();
        }
    }
    else if( currentValue != 0 && e != 0 ){
        // We need to update the existing value.
        for( int k = 0; k < this->m ; ++k ) // Go through the elements and update the value.
            if( this->elements[k].getColumn() == j && this->elements[k].getLine() == i )
                this->elements[k].setValue(e);
    }
    else if( currentValue != 0 && e == 0 ){
        int ii = this->hash(Triplet(i,j,e));
        int jj = -1; // Previous of i, when we want to remove node from pos i, we need its previous node.
        // Parse the table to check if i has any previous element.
        int idx = 0;
        while( idx < this->m && jj == -1 ){
            //std::cout << "idx = " << idx << " jj = " << jj << " ii = " << ii << '\n';
            if( this->next[idx] == ii )
                jj = idx;
            else
                idx = idx + 1;
        }
        // Find the key to be removed. Set its previous as well
        while( ii != -1 && ( this->elements[ii].getLine() == i && this->elements[ii].getColumn() == j ) ) {
            //std::cout << "jj = " << ii << " ii = " << this->next[ii] << '\n' ;
            jj = ii;
            ii = this->next[ii];
        }
        if( ii == -1 )
            std::cout << "Key does not exist.\n";
        else{
            // Find another key that hashes to i.
            bool over = false; // Becomes true when nothing hashes to i.
            int p, pp ;
            do{
                p = this->next[ii]; // First position to be checked.
                pp = ii; // Previous of p.
                while( p != -1 && this->hash(this->elements[p]) != ii ){
                    pp = p;
                    p = this->next[p];
                }
                if( p == -1 )
                    over = true;
                else{
                    this->elements[ii] = this->elements[p];
                    j = pp;
                    i = p;
                }
            } while( over );
            // Remove key from position i.
            if( jj != -1 )
                this->next[jj] = this->next[ii];
            this->elements[ii].initialize();
            this->next[ii] = -1;
            if( this->firstFree > ii )
                this->firstFree = ii;
        }
    }
    this->updateAlpha();
    if( this->alpha < 0.3 )
        this->resizeAndRehash();
}

void Matrix::updateFirstFree() {
    // Complexity : O(m)
    int current = 0;
    while( true ) {
        if (this->elements[current].getColumn() == -1 && this->elements[current].getLine() == -1){
            // Found the new firstFree
            this->firstFree = current;
            break;
        }
        current++;
    }
}

void Matrix::print() {
    for( int i = 0; i < m; ++i )
        this->elements[i].print();
    //std::cout << "Alpha = " << this->alpha << '\n' ;
}

TElem Matrix::element(int i, int j) const {
    // Complexity: Θ(m) in worst case, but on average Θ(1)
    if( i < 0 || j < 0 || i >= this->numberOfLines || j >= this->numberOfColumns )
        throw std::exception(); // Invalid i and j ( out of range )
    for( int k = 0; k < m ; ++k )
        if( this->elements[k].getLine() == i && this->elements[k].getColumn() == j ) {
            return this->elements[k].getValue();
        }
    return 0; // Element was not found so i and j are not in the matrix
}

void Matrix::updateAlpha() {
    int empty = 0;
    for( int k = 0; k < m ; ++k )
        if( this->elements[k].getColumn() == -1 &&
            this->elements[k].getLine() == -1   &&
            this->elements[k].getValue() == 0 ) {
            ++empty;
        }
    //std::cout << "\n empty =" << empty << '\n';
    this->alpha = double((empty*1.0)/(this->m*1.0));
}

void Matrix::resizeAndRehash() {
    /*

    // Initialize hash
    int new_m;
    Triplet* new_elements = new Triplet[new_m];
    int* new_next = new int[new_m];

    //for( int k = 0; k < this->m ; ++k )
    //    new_elements[k] = x;

    this->m = 10; // The hash function will modulo the hashCode % m
    this->elements = new Triplet[m];
    this->next = new int[m];
    this->firstFree = 0;
    this->alpha = 0;

    for( int i = 0; i < m ; ++i ){
        this->elements[i].initialize();
        this->next[i] = -1;
    }

     */
}

Triplet Matrix::getFromPos(int idx) const {
    return this->elements[idx];
}

int Matrix::getM() const {
    return this->m;
}

/*
Iterator Matrix::iterator() const {
    return Iterator(*this);
}
 */
