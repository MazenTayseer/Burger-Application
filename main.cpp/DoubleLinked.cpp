#include "DoubleLinked.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

Doublelinked::Doublelinked()
    : first(0), mySize(0)
{}

Doublelinked::Doublelinked(const Doublelinked& origList)
    : first(0), mySize(origList.mySize)
{
    if (mySize == 0) return;
    Doublelinked::NodePointer origPtr, lastPtr;
    first = new Node(origList.first->data);  // copy first node
    first->previous = 0;
    lastPtr = first;
    origPtr = origList.first->next;
    while (origPtr != 0)
    {
        lastPtr->next = new Node(origPtr->data);
        lastPtr->next->previous = lastPtr;
        origPtr = origPtr->next;
        lastPtr = lastPtr->next;
    }
}


inline Doublelinked::~Doublelinked() {
    Doublelinked::NodePointer prev = first, ptr;
    while (prev != 0)
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

bool Doublelinked::empty()
{
    return mySize == 0;
}


const Doublelinked& Doublelinked :: operator = (const Doublelinked& rightSide) {
    mySize = rightSide.mySize;

    if (mySize == 0) {
        this -> ~Doublelinked();
        first = 0;
        return *this;
    }

    if (this != &rightSide) {
        this -> ~Doublelinked();
        Doublelinked::NodePointer origPtr, lastPtr;
        first = new Node(rightSide.first->data);  // copy first node
        first->previous = 0;
        lastPtr = first;
        origPtr = rightSide.first->next;
        while (origPtr != 0)
        {
            lastPtr->next = new Node(origPtr->data);
            lastPtr->next->previous = lastPtr;
            origPtr = origPtr->next;
            lastPtr = lastPtr->next;
        }

    }
    return *this;
}

void Doublelinked::insert(SongType dataVal, int index) {
    if (index < 0 || index > mySize)
    {
        cerr << "Illegal location to insert -- " << index << endl;
        return;
    }
    mySize++;
    Doublelinked::NodePointer newPtr = new Node(dataVal), ptr = first;

    if (index == 0) {
        if (ptr != 0) {
            newPtr->next = ptr;
            ptr->previous = newPtr;
            newPtr->previous = 0;
            first = newPtr;
        }
        else {
            first = newPtr;
            newPtr->previous = 0;
        }
    }

    else {
        for (int i = 1; i < index; i++)
            ptr = ptr->next;

        newPtr->next = ptr->next;
        newPtr->previous = ptr;
        if (ptr->next != 0) {
            ptr->next->previous = newPtr;
        }
        ptr->next = newPtr;
    }
}



void Doublelinked::push_back(SongType dataVal) {
    Doublelinked::NodePointer newPtr = new Node(dataVal), ptr = first;
    
    if (empty()) {
        first = newPtr;
        newPtr->previous = 0;
    }
    else {
        while (ptr->next != 0) {
            ptr = ptr->next;
        }

        ptr->next = newPtr;
        newPtr->previous = ptr;
        newPtr->next = 0;
    }
    mySize++;

}

void Doublelinked::erase(int index) {
    if (index < 0 || index >= mySize)
    {
        cerr << "Illegal location to delete -- " << index << endl;
        return;
    }

    Doublelinked::NodePointer ptr = first, ptrnext, ptrprev;

    if (index == 0) {
        ptr = first;
        first = ptr->next;
        delete ptr;
        first->previous = 0;
    }
    else {
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }

        ptrnext = ptr->next;
        ptrprev = ptr->previous;

        if (index == mySize - 1) {
            ptrprev->next = ptrnext;
        }
        else {
            ptrprev->next = ptrnext;
            ptrnext->previous = ptrprev;
        }

        mySize--;
        delete ptr;
    }
}


SongType Doublelinked::get(int index) {
    Doublelinked::NodePointer ptr = first;
    if (index >= mySize) {
        cerr << "Index bigger than size" << endl;
        exit(1);
    }

    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }

    return ptr->data;
}


void Doublelinked::swap(int index1, int index2) {
    //string data1 = get(index1);
    //string data2 = get(index2);

    //erase(index1);
    //erase(index2);

    //insert(data1, index2);
    //insert(data2, index1);

    NodePointer firstElement = first, secondElement = first;

    for (int i = 0; i < index1; i++) {
        firstElement = firstElement->next;
    }

    for (int i = 0; i < index2; i++) {
        secondElement = secondElement->next;
    }

    SongType data1 = firstElement->data;
    SongType data2 = secondElement->data;

    firstElement->data = data2;
    secondElement->data = data1;
}


void Doublelinked::display(ostream& out) const
{
    Doublelinked::NodePointer ptr = first;
    int index = 1;
    while (ptr != 0)
    {
        out << index << ". " << ptr->data.getName() << " - " << ptr->data.getDuration() << endl;
        index += 1;
        ptr = ptr->next;
    }
}

ostream& operator<<(ostream& out, const Doublelinked& aList) {
    aList.display(out);
    return out;
}

int Doublelinked::nodeCount() {
    int count = 0;
    Doublelinked::NodePointer ptr = first;
    while (ptr != 0)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

Doublelinked Doublelinked::shuffleList() {
    Doublelinked shuffledList;
    vector<SongType> v;

    NodePointer ptr = first;
    while (ptr != nullptr) {
        v.push_back(ptr->data);
        ptr = ptr->next;
    }

    srand(time(0));
    random_shuffle(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        shuffledList.push_back(v[i]);
    }

    return shuffledList;
}
