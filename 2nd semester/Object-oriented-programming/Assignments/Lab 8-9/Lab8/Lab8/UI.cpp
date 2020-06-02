#include "UI.h"
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds
using namespace std;

void ui_help_admin() {
	cout << "As the admin you can access the following commands:\n";
	cout << "To add a new movie, enter <add> <title> <genre> <year> <link>.\n";
	cout << "To delete a new movie, enter its title <title>.\n";
	cout << "To update a existing movie, enter <title> followed by the updated info <new_genre> <new_year> <new_link>.\n";
	cout << "To end the program, enter <exit>.\n";
	cout << "To print he help menu enter <help>.\n";
	cout << "To print the list of movies enter <print>.\n";
}

void Console::run_admin() {
	cout << "You entered as admin !\n";
	while (1) {
		char raw_command[500], command[10][50], delim[] = " ";
		int words = 0;
		cout << "Enter command : ";
		cin.getline(raw_command, 499);
		char* token = strtok(raw_command, delim);
		while (token) {
			strcpy(command[words], token);
			++words;
			token = strtok(NULL, delim);
		}
		if (strcmp(command[0], "exit") == 0 && words == 1)
			return;
		else if (strcmp(command[0], "add") == 0 && words == 5) {
			int year = atoi(command[3]);
			this->ctrl.addMovieToRepository(command[1], command[2], year, 0, command[4]);
			cout << "The given movie was successfully added.\n";
			std::ofstream file_name;
			file_name.open("data.txt");
			/*
			DynamicVector<Movie> aux = this->ctrl.getMovies();
			for (int i = 0; i < aux.getSize() - 1; ++i)
				file_name << aux.getOne(i).toString();
			file_name << aux.getOne(aux.getSize() - 1).getTitle() << ' ' << aux.getOne(aux.getSize() - 1).getGenre() << ' ' << aux.getOne(aux.getSize() - 1).getYear() << ' ' << aux.getOne(aux.getSize() - 1).getLikes() << ' ' << aux.getOne(aux.getSize() - 1).getLink();
			*/
			std::vector<Movie> aux = this->ctrl.getMovies();
			for (auto it = aux.begin(); it != aux.end(); ++it) 
				file_name << (*it) << '\n';
		}
		else if (strcmp(command[0], "print") == 0 && words == 1) {
			cout << "The list of movies is:\n";
			/*
			DynamicVector<Movie> movies = this->ctrl.getMovies();
			std::vector<Movie> aux = this->ctrl.getMovies();
			for (int i = 0; i < movies.getSize(); ++i)
				cout << movies.getOne(i).toString();
			*/
			std::vector<Movie> aux = this->ctrl.getMovies();
			for (auto it = aux.begin(); it != aux.end(); ++it) {
				cout << (*it).toString() << '\n';
			}
		}
		else if (strcmp(command[0], "help") == 0) {
			ui_help_admin();
		}
		else if (strcmp(command[0], "delete") == 0 && words == 2) {
			if (this->ctrl.deleteMovie(command[1])) {
				cout << "The movie was deleted successfully!\n";
				std::ofstream file_name;
				file_name.open("data.txt");
				/*
				DynamicVector<Movie> aux = this->ctrl.getMovies();
				for (int i = 0; i < aux.getSize() - 1; ++i)
					file_name << aux.getOne(i).toString();
				file_name << aux.getOne(aux.getSize() - 1).getTitle() << ' ' << aux.getOne(aux.getSize() - 1).getGenre() << ' ' << aux.getOne(aux.getSize() - 1).getYear() << ' ' << aux.getOne(aux.getSize() - 1).getLikes() << ' ' << aux.getOne(aux.getSize() - 1).getLink();
				*/
				std::vector<Movie> aux = this->ctrl.getMovies();
				for (auto it = aux.begin(); it != aux.end(); ++it)
					file_name << (*it) << '\n';
			}
			else
				cout << "The movie was not deleted.\n";
		}
		else if (strcmp(command[0], "update") == 0 && words == 5) {
			if (this->ctrl.updateMovie(command[1], command[2], atoi(command[3]), command[4])) {
				cout << "The movie was updated successfully.!\n";
				std::ofstream file_name;
				file_name.open("data.txt");
				/*
				DynamicVector<Movie> aux = this->ctrl.getMovies();
				for (int i = 0; i < aux.getSize() - 1; ++i)
					file_name << aux.getOne(i).toString();
				file_name << aux.getOne(aux.getSize() - 1).getTitle() << ' ' << aux.getOne(aux.getSize() - 1).getGenre() << ' ' << aux.getOne(aux.getSize() - 1).getYear() << ' ' << aux.getOne(aux.getSize() - 1).getLikes() << ' ' << aux.getOne(aux.getSize() - 1).getLink();
				*/
				std::vector<Movie> aux = this->ctrl.getMovies();
				for (auto it = aux.begin(); it != aux.end(); ++it)
					file_name << (*it) << '\n';
			}
			else
				cout << "The movie was not updated successfully.!\n";
		}
		else
			cout << "Invalid command. Enter <help> to print the help menu.\n";
	}
};

void ui_help_user() {
	cout << "As the user you can access the following commands:\n";
	cout << "To end the program, enter <exit>.\n";
	cout << "To print he help menu enter <help>.\n";
	cout << "To print the list of movies enter <print>.\n";
	cout << "To print the list of movies of a given genre enter <print> <chosen_genre>.\n";
	cout << "To print the watchlist enter <see>.\n";
	cout << "To print the list of movies enter <print>.\n";
}
void Console::run_user() {
	cout << "You entered as user !\n";
	while (1) {
		char raw_command[500], command[10][50], delim[] = " ";
		int words = 0;
		cout << "Enter command : ";
		cin.getline(raw_command, 499);
		char* token = strtok(raw_command, delim);
		while (token) {
			strcpy(command[words], token);
			++words;
			token = strtok(NULL, delim);
		}
		if (strcmp(command[0], "exit") == 0 && words == 1)
			return;
		else if (strcmp(command[0], "help") == 0 && words == 1)
			ui_help_user();
		else if (strcmp(command[0], "print") == 0 && words == 1) {
			cout << "The list of movies is:\n";
			/*
			DynamicVector<Movie> movies = this->ctrl.getMovies();
			for (int i = 0; i < movies.getSize(); ++i)
				cout << movies.getOne(i).toString();
			*/
			std::vector<Movie> aux = this->ctrl.getMovies();
			for (auto it = aux.begin(); it != aux.end(); ++it) {
				cout << (*it).toString() << '\n';
			}
		}
		else if (strcmp(command[0], "print") == 0 && words == 2) {
			char answer[10];
			int added = 0;
			cout << "The list of movies of genre " << command[1] << " is:\n";
			/*
			DynamicVector<Movie> movies = this->ctrl.getGenre(command[1]);
			for (int i = 0; i < movies.getSize(); ++i)
			{
				if (!this->ctrl.checkMovieInWatchlist(movies.getOne(i))) {
					ShellExecuteA(NULL, NULL, "brave.exe", movies.getOne(i).getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
					cout << "Type <yes> if you want to add this movie to the watchlist, <no> otherwise. Now, type your answer: ";
					cin >> answer;
					if (strcmp(answer, "yes") == 0) {
						cout << movies.getOne(i).getTitle() << " was added to the watchlist.\n";
						this->ctrl.addMovieToWatchlist(movies.getOne(i));
						++added;
					}
					else if (strcmp(answer, "no") == 0)
						cout << movies.getOne(i).getTitle() << " was not added to the watchlist.\n";
					else if (strcmp(answer, "stop") == 0) {
						cout << "The trailers will stop.\n";
						break;
					}
				}
				if (i == movies.getSize() - 1)
					i = -1;
				if (movies.getSize() == added)
					break;
				cout << "Now the next trailer will be opened.\n";
				this_thread::sleep_for(std::chrono::seconds(2));
			}
			*/
			std::vector<Movie> movies = this->ctrl.getGenre(command[1]);
			int i = 0;
			for (auto it = movies.begin(); it != movies.end(); ++it, ++i)
			{
				if (!this->ctrl.checkMovieInWatchlist(*it)) {
					ShellExecuteA(NULL, NULL, "brave.exe", (*it).getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
					cout << "Type <yes> if you want to add this movie to the watchlist, <no> otherwise. Now, type your answer: ";
					cin >> answer;
					if (strcmp(answer, "yes") == 0) {
						cout << (*it).getTitle() << " was added to the watchlist.\n";
						this->ctrl.addMovieToWatchlist(*it);
						++added;
					}
					else if (strcmp(answer, "no") == 0)
						cout << (*it).getTitle() << " was not added to the watchlist.\n";
					else if (strcmp(answer, "stop") == 0) {
						cout << "The trailers will stop.\n";
						break;
					}
				}
				if (i == movies.size() - 1)
					i = -1;
				if (movies.size() == added)
					break;
				cout << "Now the next trailer will be opened.\n";
				this_thread::sleep_for(std::chrono::seconds(2));
			}
		}
		else if (strcmp(command[0], "delete") == 0 && words == 2) {
			cout << "Did you like the movie? Enter <yes> or <no>: ";
			char answer[10];
			cin >> answer;
			if (strcmp(answer, "no")) {
				if (this->ctrl.likeMovie(command[1]))
					cout << "The movie " << command[1] << " was liked.\n";
				else
					cout << "The movie " << command[1] << " was not liked.\n";
			}
			Movie m{ command[1],"",0,0,"" };
			if (!this->ctrl.checkMovieInWatchlist(m))
				cout << "The movie " << command[1] << " was not deleted. It does not exist in the watchlist.\n";
			else {
				cout << "The movie " << command[1] << " was deleted.\n";
				this->ctrl.deleteMovieFromWatchlist(command[1]);
			}
			std::ofstream file_name;
			file_name.open("data.txt");
			std::vector<Movie> aux = this->ctrl.getMovies();
			for (auto it = aux.begin(); it != aux.end(); ++it) {
				file_name << (*it).toString() << '\n';
			}
		}
		else if (strcmp(command[0], "see") == 0) {
			/*
			DynamicVector<Movie> watchlist = this->ctrl.getWatchlist();
			if (watchlist.getSize() == 0)
				cout << "The watchlist is empty!\n";
			else {
				cout << "The watchlist:\n";
				for (int i = 0; i < watchlist.getSize(); ++i) {
					cout << watchlist.getOne(i).toString();
				}
			}
			*/
			std::vector<Movie> watchlist = this->ctrl.getWatchlist();
			if (watchlist.size() == 0)
				cout << "The watchlist is empty!\n";
			else {
				cout << "The watchlist is:\n";
				for (auto it = watchlist.begin(); it != watchlist.end(); ++it)
					cout << (*it).toString();
				cout << '\n';
			}
		}
		else
			cout << "Invalid command. Enter <help> to print the help menu.\n";
	}
}

void Console::run() {
	while (1) {
		char mod[10];
		cout << "Input enter mode. Enter either <admin> or <user>: ";
		cin >> mod;
		if (std::strcmp(mod, "admin") == 0) {
			Console::run_admin();
			break;
		}
		else if (std::strcmp(mod, "user") == 0) {
			Console::run_user();
			break;
		}
		else
			cout << "Wrong input. Choose either admin or user.\n";
	}
}