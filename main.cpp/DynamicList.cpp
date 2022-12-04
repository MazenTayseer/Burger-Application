#include "DynamicList.h"
#include <cassert>

List::List(int maxSize) : mySize(0), myCapacity(maxSize) {
    myArray = new(nothrow) ElementType[myCapacity];
    assert(myArray != nullptr);
}

bool List::empty() const {
    return mySize == 0;
}

List::~List() {
    delete myArray;
}


List::List(const List& origList)
    : mySize(origList.mySize), myCapacity(origList.myCapacity) {
    //mySize=origList.mySize;
    //myCapacity=origList.myCapacity;
    //--- Get new array for copy
    myArray = new(nothrow) ElementType[myCapacity];

    if (myArray != nullptr) { // check if memory available

        //--- Copy origList's elements into this new array
        for (int i = 0; i < mySize; i++) {
            myArray[i] = origList.myArray[i];
        }
    }
    else {
        cerr << "*** Inadequate memory to allocate storage for list ***\n";
        exit(1);
    }
}


List& List::operator=(const List& rightHandSide) {
    if (this != &rightHandSide) {
        if (myCapacity != rightHandSide.myCapacity) {
            delete myArray;
            myCapacity = rightHandSide.myCapacity;
            myArray = new(nothrow) ElementType[myCapacity];
        }
    }

    mySize = rightHandSide.mySize;
    for (int i = 0; i < mySize; i++) {
        myArray[i] = rightHandSide.myArray[i];
    }
    return *this;
}

void List::insert(ElementType item, int pos) {
    if (mySize == myCapacity) {
        cerr << "Error, not enough memory to store data in list.";
        exit(0);
    }

    if (pos < 0 || pos > mySize) {
        cerr << "Error, cannot place in that position.";
        exit(0);
    }

    for (int i = mySize; i > pos; i--) {
        myArray[i] = myArray[i - 1];
    }
    myArray[pos] = item;
    mySize++;
}

void List::erase(int pos) {
    if (mySize == 0) {
        cerr << "*** List is empty ***\n";
        exit(0);
    }

    if (pos < 0 || pos >= mySize) {
        cerr << "Error, cannot erase that position.";
        exit(0);
    }

    for (int i = pos; i < mySize; i++) {
        myArray[i] = myArray[i + 1];
    }
    mySize--;
}

void List::display(std::ostream& out) const {
    for (int i = 0; i < mySize; i++) {
        out << myArray[i] << " ";
    }
}

List List::operator-(const List& list2) {
    List alist, finalList;
    int listSize = mySize + list2.mySize;

    for (int i = 0; i < mySize; i++) {
        alist.insert(myArray[i], i);
    }

    int index = 0;
    for (int i = mySize; i < listSize; i++) {
        alist.insert(list2.myArray[index], i);
        index += 1;
    }

    int finalIndex = 0;
    for (int i = 0; i < alist.mySize - 1; i++) {
        for (int j = i + 1; j < alist.mySize; j++) {
            if (alist.myArray[j] == alist.myArray[i]) {
                finalList.insert(alist.myArray[j], finalIndex);
                finalIndex += 1;
            }
        }
    }

    return finalList;
}

void List::eraseAll(int index) {
    if (index >= mySize || index < 0) {
        cerr << "Error Occured";
        exit(1);
    }

    ElementType target = myArray[index];
    for (int i = 0; i < mySize; i++) {
        if (myArray[i] == target) {
            erase(i);
        }
    }
}

ostream& operator<<(ostream& out, const List& aList) {
    aList.display(out);
    return out;
}