#include "Domain.h"
#pragma once

template<typename TElement>
class Comparator {
public:
	// Default constructor
	Comparator() {};
	// Pure virtual function of comparison of two elements.
	virtual bool compare(const TElement& e1, const TElement& e2) const = 0;
	// Default destructor
	~Comparator() {};
};

class ComparatorAscendingByTitle : public Comparator<Movie> {
public:
	/* This function campares two Movies by their title.
		Input: m1, m2
		Preconditions : m1, m2 - movies
		Output: true/false
		Postconditions: true if the element should be swapped
						false otherwise
	*/
	bool compare(const Movie& m1,const Movie& m2) const override{
		if (m1.getTitle() > m2.getTitle())
			return true;
		return false;
	}
};

class ComparatorAscendingByLikes : public Comparator<Movie> {
public:
	/* This function campares two Movies by their number of likes.
		Input: m1, m2
		Preconditions : m1, m2 - movies
		Output: true/false
		Postconditions: true if the element should be swapped
						false otherwise
	*/
	bool compare(const Movie& m1, const Movie& m2) const override{
		if (m1.getLikes() > m2.getLikes())
			return false;
		return true;
	}
};