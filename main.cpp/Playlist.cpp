#include "Playlist.h"

Playlist::Playlist(string PlaylistName): name(PlaylistName), size(0), list()
{}

void Playlist::addToPlaylist(Song song) {
	list.push_back(*new Song(song.getInputName(), song.getName(), song.getDuration()));
}

void Playlist::deleteFromPlaylist(int index) {
	list.erase(index);
}

void Playlist::edit(int index1, int index2) {
	list.swap(index1, index2);
}

Doublelinked Playlist::shuffle() {
	Doublelinked shuffledPlaylist = list.shuffleList();

	return shuffledPlaylist;
}

void Playlist::DeletePlaylist() {
	list.~Doublelinked();
}

string Playlist::getPlaylistName() {
	return name;
}