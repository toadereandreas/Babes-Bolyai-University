#include "Repository.h"
#include <algorithm> // find

void Repository::addMovie(const Movie& m) {
	/* DynamicArray implementation
	this->movies.add(m);
	*/

	/* std implementation */
	this->movies.push_back(m);
}


Repository::Repository() {}

std::vector<Movie> Repository::getMovies(){
	return this->movies;
}

bool Repository::check_movie(const std::string& title) {
	/* DynamicArray implementation
	for (int i = 0; i < this->movies.getSize(); ++i)
		if (this->movies.getOne(i).getTitle() == title)
			return true;
	return false;
	*/

	/* std implementation */
	std::string title_key = title;
	auto it = find_if(this->movies.begin(), this->movies.end(), [&title_key]( Movie & m){ return m.getTitle() == title_key; });
	if (it != this->movies.end())
		return true; // One movie with the given title was found
	else
		return false;
}

void Repository::delete_movie(const  std::string & title) {
	/* DynamicArray implementation
	for (int i = 0; i < this->movies.getSize(); ++i)
		if (this->movies.getOne(i).getTitle() == title) {
			this->movies.remove(i);
			break;
		}
	*/
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
		if ((*it).getTitle() == title) {
			this->movies.erase(it);
			break;
		}
}

void Repository::update_movie(const std::string & title, const std::string & new_genre, const int& new_year, const std::string & new_link) {
	/* DynamicArray implementation
	for (int i = 0; i < this->movies.getSize(); ++i)
		if (this->movies.getOne(i).getTitle() == title) {
			this->movies.update(i, new_genre, new_year, new_link);
			break;
		}
	*/
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
		if ((*it).getTitle() == title) {
			Movie new_movie{ title, new_genre, new_year,(*it).getLikes(),new_link };
			this->movies.erase(it);
			this->movies.push_back(new_movie);
			break;
		}
}

std::vector<Movie> Repository::getMoviesByGenre(const std::string & genre) {
	/* DynamicArray implementation
	DynamicVector<Movie> filtered = DynamicVector<Movie>();
    for( int i = 0; i < this->movies.getSize(); ++i )
        if( this->movies.getOne(i).getGenre() == genre )
            filtered.add(this->movies.getOne(i));
    return filtered;
	*/
	std::vector<Movie> filtered;
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it )
	{
		if ((*it).getGenre() == genre)
			filtered.push_back(*it);
	}
	return filtered;
}

void Repository::like_movie(const std::string & title) {
	/* DynamicArray implementation
	for (int i = 0; i < this->movies.getSize(); ++i)
		if (this->movies.getOne(i).getTitle() == title) {
			this->movies.updateLike(i, this->movies.getOne(i).getLikes() + 1);
			break;
		}
	*/
	for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
		if ((*it).getTitle() == title) {
			Movie liked_movie{ title,(*it).getGenre(),(*it).getYear(),(*it).getLikes() + 1,(*it).getLink() };
			this->movies.erase(it);
			this->movies.push_back(liked_movie);
			break;
		}
}

int Repository::getSize() const {
	/* DynamicArray implementation
	return movies.getSize();
	*/
	return this->movies.size();
}
