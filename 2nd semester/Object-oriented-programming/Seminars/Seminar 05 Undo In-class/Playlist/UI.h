#pragma once
#include "Controller.h"

class UI
{
private:
	Controller& ctrl;	// reference to the controller (controller cannot be copied!)

public:
	UI(Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printPlayListMenu();

	void addSongToRepo();
	void removeSongFromRepo();
	void displayAllSongsRepo();
	void addSongToPlaylist();
	void addAllSongsByArtistToPlaylist();
	void savePlaylistToFile();
	void undo();
};