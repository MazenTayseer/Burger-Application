#pragma once

#include <iostream>
#include "Likes.h"
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

public:
	Account(string username,string password);
	string getUsername();
	string getPassword();

	void createPlaylist(string name);
};

#endif // Account_h 