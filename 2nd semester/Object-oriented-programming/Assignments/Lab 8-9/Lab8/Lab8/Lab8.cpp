#include "UI.h"
#include <assert.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include "Domain.h"
#include "Repository.h"
#include "Bussines.h"
#include "Comparator.h"
#include <algorithm>
#include "UI.h"

void testDomain() {
	// This function tests the Domain: the Movie class
	Movie m{ "Name","Genre",1234,0,"link" };
	assert(m.getTitle() == "Name");
	assert(m.getLink() == "link");
	assert(m.getGenre() == "Genre");
	assert(m.getYear() == 1234);
	assert(m.getLikes() == 0);
	m.setLike(2);
	m.setLink("linkss");
	m.setYear(321);
	m.setGenre("aaaa");
	assert(m.getLink() == "linkss");
	assert(m.getGenre() == "aaaa");
	assert(m.getYear() == 321);
	assert(m.getLikes() == 2);
	std::string test_string = m.getTitle() + ' ' + m.getGenre() + ' ' + std::to_string(m.getYear()) + ' ' + std::to_string(m.getLikes()) + ' ' + m.getLink();
	assert(m.toString() == test_string);
}


void testRepository() {
	Repository test_repo;
	assert(test_repo.getSize() == 0);
	Movie movie1{ "JohnWick", "Action", 2019, 0, "https://www.youtube.com/watch?v=pU8-7BX9uxs" };
	Movie movie2{ "Fast&Furious", "Action", 2019, 0, "https://www.youtube.com/watch?v=nYTRzYZrcUg" };
	Movie movie3{ "Split", "Horror", 2017, 0, "https://www.youtube.com/watch?v=mJXACd2zAx8" };
	test_repo.addMovie(movie1);
	test_repo.addMovie(movie2);
	test_repo.addMovie(movie3);
	assert(test_repo.getSize() == 3);
	assert(test_repo.check_movie("Split") == true);
	assert(test_repo.check_movie("Xasd") == false);
	test_repo.delete_movie("JohnWick");
	assert(test_repo.getSize() == 2);
	assert(test_repo.check_movie("JohnWick") == false);
	test_repo.like_movie("Split");
	test_repo.update_movie("Split", "dddd", 12312, "linsdsd");
}

void testController() {
	Repository test_repo;
	assert(test_repo.getSize() == 0);
	Movie movie1{ "JohnWick", "Action", 2019, 0, "https://www.youtube.com/watch?v=pU8-7BX9uxs" };
	Movie movie2{ "Fast&Furious", "Action", 2019, 0, "https://www.youtube.com/watch?v=nYTRzYZrcUg" };
	Movie movie3{ "Split", "Horror", 2017, 0, "https://www.youtube.com/watch?v=mJXACd2zAx8" };
	Controller ctrl{ test_repo };
	assert(ctrl.getWatchlistSize() == 0);
	ctrl.addMovieToWatchlist(movie1);
	assert(ctrl.getWatchlistSize() == 1);
	ctrl.deleteMovie("Fast&Furious");
	assert(!ctrl.checkMovieInWatchlist(movie2));
	assert(ctrl.checkMovieInWatchlist(movie1));
}

std::vector<Movie> sort(std::vector<Movie> movies, Comparator<Movie>* comp) {
	for( unsigned i = 0; i < movies.size(); ++i )
		for(unsigned j = i + 1; j < movies.size(); ++j )
			if (comp->compare(movies[i], movies[j]))
			{
				Movie aux = movies[i];
				movies[i] = movies[j];
				movies[j] = aux;
			}
	return movies;
}

void testCompare() {
	std::vector<Movie> aux;
	Movie movie1{ "JohnWick", "Action", 2019, 1, "https://www.youtube.com/watch?v=pU8-7BX9uxs" };
	Movie movie2{ "Fast&Furious", "Action", 2019, 0, "https://www.youtube.com/watch?v=nYTRzYZrcUg" };
	Movie movie3{ "Split", "Horror", 2017, 2, "https://www.youtube.com/watch?v=mJXACd2zAx8" };
	Movie movie4{ "A","",0,0,"" };
	Movie movie5{ "Z", "", 0, 3, ""};
	aux.push_back(movie1);
	aux.push_back(movie2);
	aux.push_back(movie3);
	aux.push_back(movie4);
	aux.push_back(movie5);

	ComparatorAscendingByTitle* cmp_asc_by_title = new ComparatorAscendingByTitle;
	std::vector<Movie> aux_sorted_by_name = sort(aux, cmp_asc_by_title);
	assert(aux_sorted_by_name[0].toString() == movie4.toString());
	assert(aux_sorted_by_name[1].toString() == movie2.toString());
	assert(aux_sorted_by_name[2].toString() == movie1.toString());
	assert(aux_sorted_by_name[3].toString() == movie3.toString());
	assert(aux_sorted_by_name[4].toString() == movie5.toString());

	ComparatorAscendingByLikes* cmp_by_likes = new ComparatorAscendingByLikes;
	std::vector<Movie> aux_sorted_by_likes = sort(aux_sorted_by_name, cmp_by_likes);
	assert(aux_sorted_by_likes[0].toString() == movie5.toString());
	assert(aux_sorted_by_likes[1].toString() == movie3.toString());
	assert(aux_sorted_by_likes[2].toString() == movie1.toString());
	assert(aux_sorted_by_likes[3].toString() == movie2.toString());
	assert(aux_sorted_by_likes[4].toString() == movie4.toString());
	delete cmp_asc_by_title;
	delete cmp_by_likes;
}

void testAll() {
	testDomain();
	testRepository();
	testController();
	testCompare();
}

int main() {
	testAll();

	Repository repo;
	std::ifstream file_name;
	file_name.open("data.txt");
	if (file_name.is_open()) {
		std::string title, genre, link, likes;
		char year[10];
		Movie movie;
		while ( !file_name.eof() ) {
			file_name >> movie;
			if (!repo.check_movie(movie.getTitle()))
				repo.addMovie(movie);
		}
		file_name.close();
	}
	else std::cout << "File was not opened correctly.\n";

	Controller ctrl{ repo };
	Console ui{ ctrl };
	ui.run();
	return 0;
}