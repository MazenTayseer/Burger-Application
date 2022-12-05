#pragma once

#include <iostream>
#include "DoubleLinked.h"
#include "Song.h"

using namespace std;

// Playlist_h
#ifndef Playlist_h
#define Playlist_h

class Playlist
{
private:
	Doublelinked list;
	string name;
	int size;

public:
	Playlist();

	Playlist(string name);

	void addToPlaylist(Song song);

	void deleteFromPlaylist(int index);

	Doublelinked shuffle();

	void edit(int index1, int index2);

	void DeletePlaylist();

	string getPlaylistName();

};

#endif // PlayList_h 