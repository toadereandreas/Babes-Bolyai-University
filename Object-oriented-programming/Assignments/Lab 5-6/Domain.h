#ifndef LAB5_6_DOMAIN_H
#define LAB5_6_DOMAIN_H
#include <iostream>

class Movie{
private:
    std::string title;
    std::string genre;
    int year;
    int likes;
    std::string link;
public:
    // Default constructor
    Movie();

    // Constructor with parameters
    Movie(const std::string &title, const std::string &genre, const int &year, const int &likes, const std::string &link);

    // Getters
    std::string getTitle() const;
    std::string getGenre() const;
    std::string getLink() const;
    int getYear() const;
    int getLikes() const;

    // Returns a string containing a movie.
    std::string toString() const;

    // Setters
    void setYear( const int &new_year );
    void setGenre( const std::string &new_genre );
    void setLink( const std::string &new_link );
    void setLike( const int &new_like );
};
#endif //LAB5_6_DOMAIN_H