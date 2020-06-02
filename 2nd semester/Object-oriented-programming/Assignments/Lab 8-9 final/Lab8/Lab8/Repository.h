#ifndef LAB5_6_REPOSITORY_H
#define LAB5_6_REPOSITORY_H
#pragma once
#include "Domain.h"
#include <cstring>
#include <string>
#include <vector>

class Repository {
private:
	//DynamicVector<Movie> movies;
	std::vector<Movie> movies;
public:
	// Default constructor
	Repository();

	/* Adds a movie to the repository.
	 * Input : m, a movie
	 * Output:
	 */
	void addMovie(const Movie& m);

	/* Returns all movies.
	 * Input :
	 * Output: a DynamicVector that contains all the movies from the repository
	 */
	//DynamicVector<Movie> getMovies();
	std::vector<Movie> getMovies();

	/* Returns all the movies which are of a given genre.
	 * Input : genre, a string representing the genre of the movies that will be returned
	 * Output: a DynamicVector that contains all the movies from the repository which are of the given genre
	 */
	//DynamicVector<Movie> getMoviesByGenre(const std::string& genre);
	std::vector<Movie> getMoviesByGenre(const std::string& genre);

	// Returns the size of the repository.
	int getSize() const;

	/* Checks if a movie with a given title.
	 * Input : title, a string representing the title of the movie that will be searched in the repository
	 * Output: true, if a movie with the given title is in the repository
	 *         false, otherwise
	 */
	bool check_movie(const std::string& title);

	/* Deletes a movie with a given title.
	 * Input : title, a string representing the title of the movie that will be deleted
	 * Output:
	 */
	void delete_movie(const std::string& title);

	/* Updates a movie with a given title.
	 * Input : title, a string representing the title of the movie that will be updated
	 *         new_genre, the updated genre of the movie with the given title
	 *         new_year, the updated year of the movie with the given title
	 *         new_link, the updated link of the movie with the given title
	 * Output:
	 */
	void update_movie(const std::string& title, const std::string& new_genre, const int& new_year, const std::string& new_link);

	/* Increases the likes of a given movie by its title.
	 * Input : title, a string representing the title of the movie that will be liked
	 * Output:
	 */
	void like_movie(const std::string& title);
};
#endif //LAB5_6_REPOSITORY_H
