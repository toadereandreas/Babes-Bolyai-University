#include "Domain.h"
#pragma once

template<typename TElement>
class Comparator {
public:
	Comparator() {};

	virtual bool compare(const TElement& e1, const TElement& e2) const = 0;

	~Comparator() {};
};

class ComparatorAscendingByTitle : public Comparator<Movie> {
public:
	bool compare(const Movie& m1,const Movie& m2) const override{
		if (m1.getTitle() > m2.getTitle())
			return true;
		return false;
	}
};

class ComparatorAscendingByLikes : public Comparator<Movie> {
public:
	bool compare(const Movie& m1, const Movie& m2) const override{
		if (m1.getLikes() > m2.getLikes())
			return false;
		return true;
	}
};