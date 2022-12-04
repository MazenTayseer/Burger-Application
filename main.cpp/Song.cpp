#include "Song.h"
#include <Windows.h>

Song::Song(string name, int duration): name(name), duration(duration)
{}

void Song::playSong() {
	string inputStr = "play " + name + ".mp3";
	LPSTR lpstr = const_cast<char*>(inputStr.c_str());
	mciSendString(lpstr, NULL, 0, NULL);
}

void Song::pauseSong() {
	string inputStr = "pause " + name + ".mp3";
	LPSTR lpstr = const_cast<char*>(inputStr.c_str());
	mciSendString(lpstr, NULL, 0, NULL);
}

void Song::resumeSong() {
	string inputStr = "resume " + name + ".mp3";
	LPSTR lpstr = const_cast<char*>(inputStr.c_str());
	mciSendString(lpstr, NULL, 0, NULL);
}

string Song::getName() {
	return name;
}

int Song::getDuration() {
	return duration;
}