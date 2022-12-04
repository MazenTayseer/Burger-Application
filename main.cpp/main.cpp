#include <iostream>
#include <Windows.h>
#include <vector>

#include "Account.h"
#include "DoubleLinked.h"


using namespace std;
// Double linked: Playlist, Likes
// Queue: Play next ,Play later

vector<Account> accounts;
bool signUp(string username, string password);
bool logIn(string username, string password);
void songList();

int main()
{
	Doublelinked l1;
	l1.push_back("1");
	l1.push_back("2");
	l1.push_back("3");
	l1.push_back("4");
	l1.push_back("5");
	l1.push_back("6");

	l1.erase(5);
	l1.display(cout);

	cout << endl;

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

		int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			songList();
			goto dashboard;
			break;

		case 2:
			bool playing = mciSendString("play DripTooHard.mp3", NULL, 0, NULL);
			while (true) {
				int command;
				cout << "1 - Pause" << endl;
				cout << "2 - Resume" << endl;
				cout << "3 - play" << endl;
				cin >> command;

				if (command == 1) {
					mciSendString("pause DripTooHard.mp3", NULL, 0, NULL);
				}
				else if (command == 2) {
					mciSendString("resume DripTooHard.mp3", NULL, 0, NULL);
				}
				else {
					cout << "WRONG INPUT" << endl;
				}
			}
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
	cout << "1 - Drip Too Hard" << endl;
	cout << "==================" << endl;
}



