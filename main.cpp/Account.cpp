#include "Account.h"

Account::Account(string user, string pass): username(user), password(pass), likes() 
{}

string Account::getUsername() {
	return username;
}

string Account::getPassword() {
	return password;
}

void Account::createPlaylist(string name) {
	Playlist newPlaylist = *new Playlist(name);

	playlists.push_back(newPlaylist);
}


Playlist Account::accessPlaylist(int index){
	Playlist currentPL = playlists.get(index);
	return currentPL;
}
