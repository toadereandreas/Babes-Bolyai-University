#include "Repository.h"

void Repository::addMovie( const Movie &m ){
    this->movies.add(m);
}


Repository::Repository(){}

DynamicVector<Movie> Repository::getMovies(){
    return this->movies;
}

bool Repository::check_movie( const std::string &title ){
    for( int i = 0; i < this->movies.getSize(); ++i )
        if( this->movies.getOne(i).getTitle() == title )
            return true;
    return false;
}

void Repository::delete_movie( const  std::string &title ){
    for( int i = 0; i < this->movies.getSize(); ++i )
        if( this->movies.getOne(i).getTitle() == title ) {
            this->movies.remove(i);
            break;
        }
}

void Repository::update_movie( const std::string &title, const std::string &new_genre, const int &new_year, const std::string &new_link ){
    for( int i = 0; i < this->movies.getSize(); ++i )
        if( this->movies.getOne(i).getTitle() == title ) {
            this->movies.update(i, new_genre, new_year, new_link);
            break;
        }
}

DynamicVector<Movie> Repository::getMoviesByGenre( const std::string &genre ) {
    DynamicVector<Movie> filtered = DynamicVector<Movie>();
    for( int i = 0; i < this->movies.getSize(); ++i )
        if( this->movies.getOne(i).getGenre() == genre )
            filtered.add(this->movies.getOne(i));
    return filtered;
}

void Repository::like_movie( const std::string &title ) {
    for( int i = 0; i < this->movies.getSize(); ++i )
        if( this->movies.getOne(i).getTitle() == title ){
            this->movies.updateLike(i,this->movies.getOne(i).getLikes()+1);
            break;
        }
}

int Repository::getSize() const {
    return movies.getSize();
}
