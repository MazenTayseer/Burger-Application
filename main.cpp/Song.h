#pragma once

#include <iostream>
#include "Playlist.h"
using namespace std;

// Song_h
#ifndef Song_h
#define Song_h

class Song
{
private:
	string inputName;
	string name;
	string duration;

public:
	Song();

	Song(string inputName, string name, string duration);

	void playSong();

	void pauseSong();

	void resumeSong();

	void nextSong(Song song, Playlist currentList);

	void previousSong(Song song, Playlist currentList);

	string getName();

	string getDuration();

	string getInputName();

	//void stopSong();
};

#endif // Song_h 