#include "Song.h"
#include <Windows.h>

Song::Song(string inputName, string name, string duration): inputName(inputName), name(name), duration(duration)
{}

void Song::playSong() {
	string inputStr = "play ./Songs/" + inputName + ".mp3";
	LPSTR lpstr = const_cast<char*>(inputStr.c_str());
	mciSendString(lpstr, NULL, 0, NULL);
}

void Song::pauseSong() {
	string inputStr = "pause ./Songs/" + inputName + ".mp3";
	LPSTR lpstr = const_cast<char*>(inputStr.c_str());
	mciSendString(lpstr, NULL, 0, NULL);
}

void Song::resumeSong() {
	string inputStr = "resume ./Songs/" + inputName + ".mp3";
	LPSTR lpstr = const_cast<char*>(inputStr.c_str());
	mciSendString(lpstr, NULL, 0, NULL);
}

string Song::getName() {
	return name;
}

string Song::getDuration() {
	return duration;
}

string Song::getInputName() {
	return inputName;
}