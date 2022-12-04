#include "Likes.h"

Likes::Likes() : name("Likes"), size(0), list()
{}

void Likes::addToLikes(string song) {
	list.push_back(song);
}

void Likes::deleteFromLikes(int index) {
	list.erase(index);
}

void Likes::edit(int index1, int index2) {
	list.swap(index1, index2);
}

Doublelinked Likes::shuffle() {
	Doublelinked shuffledPlaylist = list.shuffleList();

	return shuffledPlaylist;
}


