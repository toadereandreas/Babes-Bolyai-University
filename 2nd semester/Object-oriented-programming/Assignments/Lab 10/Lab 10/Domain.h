#pragma once
#ifndef LAB5_6_DOMAIN_H
#define LAB5_6_DOMAIN_H
#include <iostream>
#include <istream>

class Movie {
public:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string link;

	// Default constructor
	Movie();

	// Constructor with parameters
	Movie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& link);

	// Getters
	std::string getTitle() const;
	std::string getGenre() const;
	std::string getLink() const;
	int getYear() const;
	int getLikes() const;

	// Returns a string containing a movie.
	std::string toString() const;

	// Setters
	void setYear(const int& new_year);
	void setGenre(const std::string& new_genre);
	void setLink(const std::string& new_link);
	void setLike(const int& new_like);

	// Overload >>
	friend std::istream& operator>>(std::istream& is, Movie& m)
	{
		int year_int, likes_int;
		char year[10], likes[10];
		is >> m.title >> m.genre >> year >> likes >> m.link;
		year_int = atoi(year);
		likes_int = atoi(likes);
		m.year = year_int;
		m.likes = likes_int;
		return is;
	}

	// Overload <<
	friend std::ostream& operator<<(std::ostream& os, Movie& m)
	{
		os << m.getTitle() << ' ' << m.getGenre() << ' ' << m.getYear() << ' ' << m.getLikes() << ' ' << m.getLink();
		return os;
	}
};
#endif //LAB5_6_DOMAIN_H