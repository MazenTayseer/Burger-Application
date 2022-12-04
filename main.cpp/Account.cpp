#include "Account.h"

Account::Account(string user, string pass): username(user), password(pass) {

}

string Account::getUsername() {
	return username;
}

string Account::getPassword() {
	return password;
}
