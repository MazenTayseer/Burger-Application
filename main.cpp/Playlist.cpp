#include "Playlist.h"

Playlist::Playlist(string PlaylistName): name(PlaylistName), size(0), list()
{}

void Playlist::addToPlaylist(string song) {
	list.push_back(song);
}

void Playlist::deleteFromPlaylist(int index) {
	list.erase(index);
}

void Playlist::edit(int index1, int index2) {
	list.swap(index1, index2);
}

void Playlist::DeletePlaylist() {
	list.~Doublelinked();
}

