#pragma once

#include <iostream>
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
	Song(string inputName, string name, string duration);

	void playSong();

	void pauseSong();

	void resumeSong();

	string getName();

	string getDuration();

	string getInputName();

	//void stopSong();
};

#endif // Song_h 