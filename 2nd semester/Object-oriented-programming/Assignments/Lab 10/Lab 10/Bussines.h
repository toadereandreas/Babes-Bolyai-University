#pragma once
#ifndef LAB5_6_BUSSINES_H
#define LAB5_6_BUSSINES_H
#include "Repository.h"
#include <Domain.h>

class Controller {
private:
	Repository& repo;
public:
	std::vector<Movie> watchlist;

	// The constructor
	explicit Controller(Repository& r);

	/* Adds a movie to the watchlist.
	 * Input : m, is a movie
	 * Output:
	 */
	void addMovieToWatchlist(const Movie& m);

	/* Adds a movie with given data to the repository.
	 * Input:  title, a string representing the title
	 *         genre, a string representing the genre
	 *         year, an integer representing the year
	 *         likes, an integer representing the likes
	 *         link, an string representing the link
	 * Output:
	 */
	void addMovieToRepository(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& link);

	/* Deletes a movie based on a given title, if it exists.
	 * Input : title, a string representing the title
	 * Output: true, if the movie with the given title was deleted
	 *         false, if the movie with the given title was not deleted
	 */
	bool deleteMovie(const std::string& title);

	/* Updates a movie information ( genre, year and link ) based on a given title, if it exists.
	 * Input : title, a string representing the title
	 *         new_genre, a string representing the new genre of the movie with the given title
	 *         new_year, an integer representing the new year of the movie with the given title
	 *         new_link, a string representing the new link of the movie with the given title
	 * Output: true, if the movie with the given title was updated
	 *         false, if the movie with the given title was not updated
	 */
	bool updateMovie(const std::string& title, const std::string& new_genre, const int& new_year, const std::string& new_link);

	/* Likes a movie based on a given title, if it exists.
	 * Input : title, a string representing the title
	 * Output: true, if the movie with the given title is successfully liked
	 *         false, otherwise
	 */
	bool likeMovie(const std::string& title);

	/* Checks whether the given movie is in the watchlist or not.
	 * Input : m, a movie
	 * Output: true, if the given movie is in the watchlist
	 *          false, otherwise
	 */
	bool checkMovieInWatchlist(const Movie& m);

	/* Deletes the movie from the watchlist.
	 * Input : title, a string representing the title of the movie which will be deleted
	 * Output:
	 */
	void deleteMovieFromWatchlist(const std::string& title);

	/* Returns the size of the watchlist.
	 * Input :
	 * Output: an integer, the number of movies in the watchlist
	 */
	int getWatchlistSize();

	/* Returns a DynamicArray containing the movies.
	 * Input :
	 * Output: a DynamicVector which contains all the movies from the repository
	 */
	std::vector<Movie> getMovies();

	/* Returns a DynamicArray containing the movies of a given genre.
	 * Input : genre, a string representing the genre of all movies in the returned DynamicVector
	 * Output: a DynamicVector which contains all the movies from the repository that have the given genre
	 */
	std::vector<Movie> getGenre(const std::string& genre);

	/* Returns a DynamicArray containing the movies in the watchlist.
	 * Input :
	 * Output: a DynamicVector which contains all the movies from the watchlist
	 */
	std::vector<Movie> getWatchlist();

	std::string getMoviesAsString();

	std::string getMoviesSortedAsString();

	std::string getWatchlistAsString();

	void updateRepo();

	void initialize();

	Movie returnMovieWithTitle(const std::string& title);
};

class ControllerHTML : public Controller {
public:
	// Contructor that recieves as a parameter a repo
	ControllerHTML(std::vector<Movie>& repo);

	void addMovieToWatchlist();

	// Default destructor
	~ControllerHTML();
};
#endif //LAB5_6_BUSSINES_H