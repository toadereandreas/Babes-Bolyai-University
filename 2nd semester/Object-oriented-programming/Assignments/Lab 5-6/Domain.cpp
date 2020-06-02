#include "Domain.h"
#include <string>
Movie::Movie(): title(""), genre(""), year(0), likes(0), link("") {}

Movie::Movie( const std::string &title, const std::string &genre, const int &year, const int &likes, const std::string&link ){
    this->title = title;
    this->genre = genre;
    this->year = year;
    this->likes = likes;
    this->link = link;
}

std::string Movie::getTitle() const{
    return this->title;
}

std::string Movie::getGenre() const{
    return this->genre;
}

int Movie::getYear() const{
    return this->year;
}

int Movie::getLikes() const{
    return this->likes;
}

std::string Movie::getLink() const{
    return this->link;
}

std::string Movie::toString() const {
    std::string t = this->getTitle() + " " + this->getGenre() + " " + std::to_string(this->getYear()) + " " + std::to_string(this->getLikes()) + " " + this->getLink() + "\n";
    return t ;
}

void Movie::setYear( const int &new_year ) {
    this->year = new_year;
}

void Movie::setGenre( const std::string &new_genre) {
    this->genre = new_genre;
}

void Movie::setLink( const std::string &new_link ) {
    this->link = new_link;
}

void Movie::setLike( const int &new_like ) {
    this->likes = new_like;
}