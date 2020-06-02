#include "Repository.h"
#include <algorithm> // find
#include "Validators.h"
#include <fstream>
void Repository::addMovie(const Movie& m) {
	this->movies.push_back(m);
	//this->makeRight();
}

Repository::Repository() {}

std::vector<Movie> Repository::getMovies() {
	return this->movies;
}

bool Repository::check_movie(const std::string& title) {
	std::string title_key = title;
	auto it = find_if(this->movies.begin(), this->movies.end(), [&title_key](Movie & m) { return m.getTitle() == title_key; });
	if (it != this->movies.end())
		return true; // One movie with the given title was found
	else
		return false;
}

void Repository::delete_movie(const  std::string & title) {
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
		if ((*it).getTitle() == title) {
			this->movies.erase(it);
			break;
		}
}

void Repository::update_movie(const std::string & title, const std::string & new_genre, const int& new_year, const std::string & new_link) {
	try {
		for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
			if ((*it).getTitle() == title) {
				Movie new_movie{ title, new_genre, new_year,(*it).getLikes(),new_link };
				MovieValidator validator;
				validator.validate(new_movie);
				this->movies.erase(it);
				this->movies.push_back(new_movie);
				break;
			}
	}
	catch (MovieValidationException ex)
	{
		throw ex;
	}
}

std::vector<Movie> Repository::getMoviesByGenre(const std::string & genre) {
	std::vector<Movie> filtered;
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
	{
		if ((*it).getGenre() == genre)
			filtered.push_back(*it);
	}
	return filtered;
}

void Repository::like_movie(const std::string & title) {
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
		if ((*it).getTitle() == title) {
			Movie liked_movie{ title,(*it).getGenre(),(*it).getYear(),(*it).getLikes() + 1,(*it).getLink() };
			this->movies.erase(it);
			this->movies.push_back(liked_movie);
			break;
		}
}

int Repository::getSize() const {
	return this->movies.size();
}

std::string Repository::getStringMovies() {
	std::string aux = "";
	for ( auto it = this->movies.begin(); it != this->movies.end(); ++it ) {
		aux += (*it).toString();
		aux += '\n\n';
	}
	return aux;
}
std::string Repository::getStringMoviesSorted() {
	std::vector<Movie> aux;
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
		aux.push_back((*it));
	
	sort(aux.begin(), aux.end(), [](const Movie & a, const Movie & b) {return a.getTitle() < b.getTitle(); });

	std::string auxs = "";
	for (auto it = aux.begin(); it != aux.end(); ++it) {
		auxs += (*it).toString();
		auxs += '\n\n';
	}
	return auxs;
}

void Repository::updateRepoFile() {
	std::ofstream file_name;
	file_name.open("data.txt");
	std::vector<Movie> aux;
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
		aux.push_back((*it));
	for (auto it = aux.begin(); it != aux.end(); ++it)
		file_name << (*it) << '\n';
}

void Repository::readFromFile() {
	std::ifstream file_name;
	file_name.open("data.txt");
	if (file_name.is_open()) {
		std::string title, genre, link, likes;
		char year[10];
		Movie movie;
		while (!file_name.eof()) {
			file_name >> movie;
			if (!this->check_movie(movie.getTitle()))
				this->addMovie(movie);
		}
		file_name.close();
	}
}

void Repository::makeRight() {
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
		for (auto it1 = it + 1; it1 != this->movies.end(); ++it1)
			if ((*it).getTitle() == (*it1).getTitle())
				this->delete_movie((*it).getTitle());
}

Movie Repository::returnMovieWithTitle(const std::string& title) {
	Movie x;
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
		if ((*it).getTitle() == title)
			x = (*it);
	return x;
}