#pragma once
#include "Repository.h"
#include "PlayList.h"

class Controller
{
private:
	Repository& repo;
	PlayList playList;

public:
	Controller(Repository& r) : repo{ r } {}

	Repository& getRepo() const { return repo; }
	PlayList getPlaylist() const { return playList; }

	// Adds a song with the given data to the song repository.
	void addSongToRepository(const std::string& artist, const std::string& title, double minutes, double seconds, const std::string& source);

	/*
		Adds a given song to the current playlist.
		Input: song - Song, the song must belong to the repository.
		Output: the song is added to the playlist.
	*/
	void addSongToPlaylist(const Song& song);

	// Adds all the songs from the repository, that have the given artist, to the current playlist.
	void addAllSongsByArtistToPlaylist(const std::string& artist);

	void startPlaylist();
	void nextSongPlaylist();
};

