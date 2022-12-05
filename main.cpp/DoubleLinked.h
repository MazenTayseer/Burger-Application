#pragma once


#ifndef Doublelinked_hpp
#define Doublelinked_hpp

#include <stdio.h>
#include <iostream>
#include "Song.h"
using namespace std;
typedef Song SongType;

class Doublelinked
{
private:

    class Node {
    public:

        //------ Node DATA MEMBERS
        SongType data;
        Node* next;
        Node* previous;
        //------ Node OPERATIONS
        //-- Default constrctor: initializes next member to Node()
        Node()
            : next(0), previous(0)
        {}

        //-- Explicit-value constructor:  initializes data member to dataValue
        //--                             and next member to 0
        Node(SongType dataValue)
            : data(dataValue), next(0), previous(0)
        {}
    }; //--- end of Node class

    typedef Node* NodePointer;

public:
    //------ List OPERATIONS
    Doublelinked();
    /*--------------------------------------------------------------------
     Default constructor: builds an empty List object.
     Precondition:  None
     Postcondition: first is 0 and mySize is 0.
     --------------------------------------------------------------------*/
    Doublelinked(const Doublelinked& origList);
    /*--------------------------------------------------------------------
     Copy constructor
     Precondition:  A copy of origList is needed.
     Postcondition: A distincr copy of origList has been constructed.
     --------------------------------------------------------------------*/
    ~Doublelinked();
    /*--------------------------------------------------------------------
     Destructor
     Precondition:  This list's lifetime is over.
     Postcondition: This list has been destroyed.
     --------------------------------------------------------------------*/
    const Doublelinked& operator=(const Doublelinked& rightSide);
    /*--------------------------------------------------------------------
     Assignment operator
     Precondition:  This list must be assigned a value.
     Postcondition: A copy of rightSide has been assigned to this list.
     --------------------------------------------------------------------*/
    bool empty();
    /*--------------------------------------------------------------------
     Check if this list is empty
     Precondition:  None.
     Postcondition: true is returned if this list is empty, false if not.
     --------------------------------------------------------------------*/
    void insert(SongType dataVal, int index);
    /*--------------------------------------------------------------------
     Insert a value into a list at a given index.
     Precondition:  index is a valid list index: 0 <= index <= mySize,
     Postcondition: dataVal has been inserted into the list at position
     index, provided index is valid..
     --------------------------------------------------------------------*/
    void push_back(SongType dataVal);
    /*--------------------------------------------------------------------
     Insert a value into a list at the end of the list.
     Precondition:  no precondition,
     Postcondition: dataVal has been inserted into the list at position
     index, provided index is valid..
     --------------------------------------------------------------------*/


    void erase(int index);
    /*--------------------------------------------------------------------
     Remove a value from a list at a given index.
     Precondition:  index is a valid list index:  0 <= index < mySize
     Postcondition: dataVal at list position index has been removed,
     provided index is valid.
     --------------------------------------------------------------------*/
    int search(string name);
    /*--------------------------------------------------------------------
     Search for an data value in this list.
     Precondition:  None
     Postcondition: Index of node containing dataVal is returned
     if such a node is found, -1r if not.
     --------------------------------------------------------------------*/
    void display(ostream& out) const;
    /*--------------------------------------------------------------------
     Display the contensts of this list.
     Precondition:  ostream out is open
     Postcondition: Elements of this list have been output to out.
     --------------------------------------------------------------------*/
    int nodeCount();
    /*--------------------------------------------------------------------
     Count the elements of this list.
     Precondition:  None
     Postcondition: Number of elements in this list is returned.
     --------------------------------------------------------------------*/
    SongType next(string currentSong);

    SongType previous(string currentSong);

    SongType get(int index);

    void swap(int index1, int index2);

    Doublelinked shuffleList();

private:
    //------ DATA MEMBERS
    NodePointer first;
    int mySize;
}; //--- end of List class

ostream& operator<<(ostream& out, const Doublelinked& aList);
istream& operator>>(istream& in, Doublelinked& aList);

#endif /* Doublelinked_h */