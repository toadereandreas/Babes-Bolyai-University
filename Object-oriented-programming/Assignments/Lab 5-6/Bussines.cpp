#include "Bussines.h"

void Controller::addMovieToRepository( const std::string &title, const std::string &genre, const int &year, const int &likes, const std::string &link ){
    Movie new_movie{title, genre, year, likes, link};
    this->repo.addMovie(new_movie) ;
}

DynamicVector<Movie> Controller::getMovies(){
    return this->repo.getMovies();
}

bool Controller::deleteMovie( const std::string &title ){
    if( !this->repo.check_movie(title) )
        return false;
    else {
        this->repo.delete_movie(title);
        return true;
    }
}

bool Controller::updateMovie( const std::string &title, const std::string &new_genre, const int &new_year, const std::string &new_link ) {
    if( !this->repo.check_movie(title) )
        return false;
    else{
        this->repo.update_movie(title,new_genre,new_year,new_link);
        return true;
    }
}

DynamicVector<Movie> Controller::getGenre( const std::string &genre ) {
    return this->repo.getMoviesByGenre(genre);
}

bool Controller::likeMovie( const std::string &title ) {
    if( !this->repo.check_movie(title) )
        return false;
    else{
        this->repo.like_movie(title);
        return true;
    }
}

void Controller::addMovieToWatchlist( const Movie &m ) {
    this->watchlist.add(m);
}

DynamicVector<Movie> Controller::getWatchlist() {
    return this->watchlist;
}

bool Controller::checkMovieInWatchlist( const Movie &m ) {
    for( int i = 0; i < this->watchlist.getSize(); ++i )
        if( this->watchlist.getOne(i).getTitle() == m.getTitle() )
            return true;
    return false;
}

void Controller::deleteMovieFromWatchlist( const std::string &title ) {
    for( int i = 0; i < this->watchlist.getSize(); ++i )
        if( this->watchlist.getOne(i).getTitle() == title )
            watchlist.remove(i);
}

int Controller::getWatchlistSize() {
    return this->watchlist.getSize();
}

Controller::Controller( Repository &r ) : repo{r} {}