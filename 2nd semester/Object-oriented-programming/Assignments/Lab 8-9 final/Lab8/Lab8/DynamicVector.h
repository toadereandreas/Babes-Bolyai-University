#pragma once
#ifndef ASSIGNMENT_1_DYNAMICVECTOR_H
#define ASSIGNMENT_1_DYNAMICVECTOR_H
#include "Domain.h"
/*
typedef Movie TElement;

class DynamicVector{
private:
	TElement* elems;
	int size;
	int capacity;

	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
public:
	// Default constructor for a DynamicVector
	explicit DynamicVector(int capacity = 10);

	// Copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);

	// Assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	// Adds an element to the current DynamicVector.
	void add(const TElement& e);

	// Returns the size of the dynamic vector.
	int getSize() const;

	// Returns all the elements.
	TElement* getAllElems() const;

	// Returns the element from a given position.
	TElement getOne( const int &position ) const;

	// Deletes the element from a given position.
	void remove( int position );

	// Updates the element from a given position.
	void update( const int &position, const std::string &new_genre, const int &new_year, const std::string &new_link );

	// Increments the likes of a movie.
	void updateLike( const int &position, const int &new_year );

	// Default destructor.
	~DynamicVector();
};*/

template <typename T>
class DynamicVector {
private:
	T* elems;
	int size;
	int capacity;
public:
	// Default constructor for the DynamicVector class.
	DynamicVector(int capacity = 10);

	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize();

	// Copy constructor.
	DynamicVector(const DynamicVector<T>& v);

	// Adds a new element to the DynamicVector.
	void add(const T& element);

	// Returns the size.
	int getSize() const;

	// Returns all the elements from the DynamicVector.
	T* getAllElems() const;

	// Returns the element from a given position.
	T getOne(const int& position) const;

	// Removes an element from a given position.
	void remove(const int& position);

	// Updates an element from a given position.
	void update(const int& position, const std::string& new_genre, const int& new_year, const std::string& new_link);

	// Increments the likes of a movie.
	void updateLike(const int& position, const int& new_year);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v) {
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
void DynamicVector<T>::add(const T & element)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = element;
	this->size++;
}

template <typename T>
int DynamicVector<T>::getSize() const {
	return this->size;
}

template <typename T>
T* DynamicVector<T>::getAllElems() const {
	return this->elems;
}

template <typename T>
T DynamicVector<T>::getOne(const int& position) const {
	return this->elems[position];
}

template <typename T>
void DynamicVector<T>::remove(const int& position) {
	for (int i = position + 1; i < this->size; ++i)
		this->elems[i - 1] = this->elems[i];
	this->size--;
}

template <typename T>
void DynamicVector<T>::update(const int& position, const std::string & new_genre, const int& new_year, const std::string & new_link) {
	this->elems[position].setGenre(new_genre);
	this->elems[position].setYear(new_year);
	this->elems[position].setLink(new_link);
}

template <typename T>
void DynamicVector<T>::updateLike(const int& position, const int& new_year) {
	this->elems[position].setLike(new_year);
}

template <typename T>
void DynamicVector<T>::resize() {
	this->capacity *= 2;
	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];
	delete[] this->elems;
	this->elems = els;
}
#endif //ASSIGNMENT_1_DYNAMICVECTOR_H