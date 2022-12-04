#pragma once

#include <iostream>
#include "Likes.h"
#include "LinkedList.h"
using namespace std;

// Account_h
#ifndef Account_h
#define Account_h

class Account
{
private:
	string username;
	string password;
	Likes likes;
	LinkedList playlists;

public:
	Account(string username,string password);
	string getUsername();
	string getPassword();

	void createPlaylist(string name);

	Playlist accessPlaylist(int index);
};

#endif // Account_h 