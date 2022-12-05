#include <iostream>
#include <Windows.h>
#include <vector>

#include "Account.h"
#include "DoubleLinked.h"
#include "Song.h"
#include "Queue.h"


using namespace std;
// Double linked: Playlist, Likes
// Queue: Play next ,Play later

vector<Account> accounts;
Account active("NEW", "NEW");
Doublelinked allSongsList;

bool signUp(string username, string password);
bool logIn(string username, string password);
void InitializeSongs();
void songList();

int main()
{
	InitializeSongs();
	cout << "WELCOME TO BURGER\n==================" << endl;
	
	welcomeScreen: {
		cout << "Choose a number to perform a task:\n";
		cout << "1 - sign up\n";
		cout << "2 - sign in\n";

		string username, password;
		int choice;

		cout << ">> ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter username\n>> ";
			cin >> username;

			cout << "Enter password\n>> ";
			cin >> password;

			signUp(username, password);
			goto welcomeScreen;
			break;

		case 2:
			cout << "Enter username\n>> ";
			cin >> username;

			cout << "Enter password\n>> ";
			cin >> password;

			if (!logIn(username, password)) {
				goto welcomeScreen;
			}
			else {
				for (int i = 0; i < accounts.size(); i++) {
					if (username == accounts[i].getUsername()) {
						active = accounts[i];
						break;
					}
				}
				goto dashboard;
			}
			break;

		default:
			cout << "WRONG CHOICE" << endl;
			break;
		}
	}

	dashboard: {
		cout << "Choose a number to perform a task:\n";
		cout << "1 - See songs list\n";
		cout << "2 - Play Song\n";

		int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			songList();
			goto dashboard;
			break;
		case 2:
			cout << "Choose a number to play a song:\n";
			songList();
			int num;
			cin >> num;

			allSongsList.get(num - 1).playSong();
			goto dashboard;
			break;
		}

	}



}

bool signUp(string username, string password) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].getUsername() == username) {
			cout << "USERNAME ALREADY EXISTS" << endl;
			return false;
		}
	}

	accounts.push_back(*new Account(username, password));
	cout << "ACCOUNT SUCCESSFULLY CREATED" << endl;
	return true;
}

bool logIn(string username, string password) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].getUsername() == username && accounts[i].getPassword() == password) {
			cout << "LOGGED IN SUCCESSFULLY" << endl;
			return true;
		}
	}

	cout << "WRONG USERNAME OR PASSWORD" << endl;
	return false;
}

void songList() {
	cout << "==================" << endl;
	allSongsList.display(cout);
	cout << "==================" << endl;
}

void InitializeSongs() {
	allSongsList.push_back(*new Song("DripTooHard", "Drip too hard", "02:35"));
	allSongsList.push_back(*new Song("Man7os", "Man7os", "04:06"));
	allSongsList.push_back(*new Song("Skerty", "Skerty", "03:31"));
	allSongsList.push_back(*new Song("Tharthara", "Tharthara", "03:12"));
}



