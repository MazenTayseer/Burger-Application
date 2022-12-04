#pragma once

#include <iostream>
using namespace std;

// Account_h
#ifndef Account_h
#define Account_h

class Account
{
private:
	string username;
	string password;

public:
	Account(string username,string password);
	string getUsername();
	string getPassword();


};

#endif // Account_h 