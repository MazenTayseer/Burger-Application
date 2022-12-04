#include "Account.h"

Account::Account(string user, string pass): username(user), password(pass), likes() 
{}

string Account::getUsername() {
	return username;
}

string Account::getPassword() {
	return password;
}
