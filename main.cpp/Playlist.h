#pragma once

#include <iostream>
#include "DoubleLinked.h"

using namespace std;

// Account_h
#ifndef Playlist_h
#define Playlist_h

class Playlist
{
private:
	Doublelinked list;
	string name;
	int size;

public:
	Playlist(string name);

	void addToPlaylist(string song);

	void deleteFromPlaylist(int index);

	void shuffle();

	void edit(int index1, int index2);

	void DeletePlaylist();

};

#endif // PlayList_h 