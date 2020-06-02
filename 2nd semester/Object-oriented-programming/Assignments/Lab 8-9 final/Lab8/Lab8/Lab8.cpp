#include <assert.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include "Domain.h"
#include "Tests.h"
#include "Repository.h"
#include "Bussines.h"
#include "Comparator.h"
#include <algorithm>
#include "UI.h"
#include "Validators.h"

int main() {
	testAll();
	std::cout << "The program has passes all the tests.\n";

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