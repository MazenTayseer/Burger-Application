#pragma once

#include <iostream>
#include "Song.h"
#include "DoubleLinked.h"

using namespace std;

// Likes_h
#ifndef Likes_h
#define Likes_h

class Likes
{
private:
	Doublelinked list;
	string name;
	int size;

public:
	Likes();

	void addToLikes(Song song);

	void deleteFromLikes(int index);

	Doublelinked shuffle();

	void edit(int index1, int index2);

	Doublelinked getList();

};

#endif // Likes_h 