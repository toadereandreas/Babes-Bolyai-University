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

Controller::Controller( Repository & r) : repo{ r } {}

/*
ControllerHTML::ControllerHTML( std::vector<Movie>& repo): Controller{ repo }
{
	this->addMovieToWatchlist();
}

void ControllerHTML::addMovieToWatchlist()
{
	std::ifstream fin("WatchList.html");
	std::string trash, line, name, genre, trailer;
	Movie movie;
	int year, likes, pos;

	for (int i = 0; i < 7; ++i) //the first 7 lines conain data we do not need now
	{
		getline(fin, trash);
	}

	while (true)
	{
		getline(fin, trash);

		if (trash.find("</table>") != -1)
			return;

		getline(fin, line);
		pos = line.find_first_of(">");
		line.erase(0, pos + 1);
		pos = line.find("</td>");
		line.erase(pos, line.size() - pos);
		name = line;

		getline(fin, line);
		pos = line.find_first_of(">");
		line.erase(0, pos + 1);
		pos = line.find("</td>");
		line.erase(pos, line.size() - pos);
		genre = line;

		getline(fin, line);
		pos = line.find_first_of(">");
		line.erase(0, pos + 1);
		pos = line.find("</td>");
		line.erase(pos, line.size() - pos);
		year = stoi(line);

		getline(fin, line);
		pos = line.find_first_of(">");
		line.erase(0, pos + 1);
		pos = line.find("</td>");
		line.erase(pos, line.size() - pos);
		likes = stoi(line);

		getline(fin, line);
		pos = line.find_first_of("\"");
		line.erase(0, pos + 1);
		pos = line.find("\">Link");
		line.erase(pos, line.size() - pos);
		trailer = line;

		getline(fin, trash);

		movie = Movie{ name, genre, year, likes, trailer };
		this->watchlist.push_back(movie);
	}
}*/