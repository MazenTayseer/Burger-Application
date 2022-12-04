#pragma once

#include <iostream>
using namespace std;

// Song_h
#ifndef Song_h
#define Song_h

class Song
{
private:
	string name;
	int duration;

public:
	Song(string name, int duration);

	void playSong();

	void pauseSong();

	void resumeSong();

	string getName();

	int getDuration();

	//void stopSong();
};

#endif // Song_h 