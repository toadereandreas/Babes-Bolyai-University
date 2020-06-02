#include "Bussines.h"
#include "Validators.h"
#include <fstream>

void Controller::addMovieToRepository(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& link) {
	try {
		Movie new_movie{ title, genre, year, likes, link };
		MovieValidator validator;
		validator.validate(new_movie);
		this->repo.addMovie(new_movie);
	}
	catch (MovieValidationException ex)
	{
		throw ex;
	}
}

std::vector<Movie> Controller::getMovies() {
	return this->repo.getMovies();
}

bool Controller::deleteMovie(const std::string& title) {
	if (!this->repo.check_movie(title))
		return false;
	else {
		this->repo.delete_movie(title);
		return true;
	}
}

bool Controller::updateMovie(const std::string& title, const std::string& new_genre, const int& new_year, const std::string& new_link) {
	if (!this->repo.check_movie(title))
		return false;
	else {
		this->repo.update_movie(title, new_genre, new_year, new_link);
		return true;
	}
}

std::vector<Movie> Controller::getGenre(const std::string& genre) {
	return this->repo.getMoviesByGenre(genre);
}

bool Controller::likeMovie(const std::string& title) {
	if (!this->repo.check_movie(title))
		return false;
	else {
		this->repo.like_movie(title);
		return true;
	}
}

void Controller::addMovieToWatchlist(const Movie& m) {
	this->watchlist.push_back(m);
}

std::vector<Movie> Controller::getWatchlist() {
	return this->watchlist;
}

bool Controller::checkMovieInWatchlist(const Movie& m) {
	for (auto it = this->watchlist.begin(); it != this->watchlist.end(); ++it)
		if ((*it).getTitle() == m.getTitle())
			return true;
	return false;
}

void Controller::deleteMovieFromWatchlist(const std::string & title) {
	for (auto it = this->watchlist.begin(); it != this->watchlist.end(); ++it)
		if ((*it).getTitle() == title) {
			this->watchlist.erase(it);
			break;
		}
}

int Controller::getWatchlistSize() {
	return this->watchlist.size();
}

std::string Controller::getMoviesAsString() {
	return this->repo.getStringMovies();
}

std::string Controller::getMoviesSortedAsString() {
	return this->repo.getStringMoviesSorted();
}

void Controller::updateRepo() {
	this->repo.updateRepoFile();
}

void Controller::initialize() {
	this->repo.readFromFile();
}

std::string Controller::getWatchlistAsString() {
	std::string aux = "";
	for (auto it = this->watchlist.begin(); it != this->watchlist.end(); ++it) {
		aux += (*it).toString();
		aux += '\n';
	}
	return aux;
}

Movie Controller::returnMovieWithTitle(const std::string& title)
{
	return this->repo.returnMovieWithTitle(title);
}

Controller::Controller(Repository & r) : repo{ r } {}