#include "LinkedList.h"

LinkedList::LinkedList(): first(nullptr), mySize(0) {}

bool LinkedList::empty() const {
    return mySize == 0;
}

LinkedList::~LinkedList() {
    NodePointer prev = first, ptr;
    while (prev != nullptr) {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

LinkedList::LinkedList(const LinkedList& origLinkedList)
    : first(0), mySize(origLinkedList.mySize) {
    if (mySize == 0) return;
    LinkedList::NodePointer origPtr, lastPtr;
    first = new Node(origLinkedList.first->data);  // copy first node
    lastPtr = first;
    origPtr = origLinkedList.first->next;
    while (origPtr != 0) {
        lastPtr->next = new Node(origPtr->data);
        origPtr = origPtr->next;
        lastPtr = lastPtr->next;
    }
}


void LinkedList::insert(Playlist dataVal, int index) {
    if (index > mySize || index < 0) {
        cerr << "ERROR IN INSERTING.";
        exit(1);
    }
    mySize++;
    NodePointer newPtr = new Node(dataVal), predPtr = first;
    if (index == 0) {
        newPtr->next = first;
        first = newPtr;
    }
    else {
        for (int i = 1; i < index; i++)
            predPtr = predPtr->next;
        newPtr->next = predPtr->next;
        predPtr->next = newPtr;
    }

}

void LinkedList::push_back(Playlist dataVal) {
    NodePointer newPtr = new Node(dataVal), predPtr = first;
    if (empty()) {
        newPtr->next = first;
        first = newPtr;
    }
    else {
        while (predPtr->next != nullptr) {
            predPtr = predPtr->next;
        }
        newPtr->next = predPtr->next;
        predPtr->next = newPtr;
    }
    mySize++;
}


void LinkedList::erase(int index) {
    if (index >= mySize || index < 0) {
        cerr << "ERROR IN INSERTING.";
        exit(1);
    }
    mySize--;
    NodePointer ptr, predPtr = first;
    if (index == 0) {
        ptr = first;
        first = ptr->next;
        delete ptr;
    }
    else {
        for (int i = 1; i < index; i++) {
            predPtr = predPtr->next;
        }
        ptr = predPtr->next;
        predPtr->next = ptr->next;
        delete ptr;
    }
}

const LinkedList& LinkedList::operator=(const LinkedList& rightSide) {
    mySize = rightSide.mySize;
    if (mySize == 0) {
        this->~LinkedList();
        first = nullptr;
        return *this;
    }

    if (this != &rightSide) {
        this->~LinkedList();
        NodePointer origPtr, lastPtr;
        first = new Node(rightSide.first->data);
        lastPtr = first;
        origPtr = rightSide.first->next;

        while (origPtr != nullptr) {
            lastPtr->next = new Node(origPtr->data);
            origPtr = origPtr->next;
            lastPtr = lastPtr->next;
        }
    }
    return *this;
}

void LinkedList::display(std::ostream& out) const {
    NodePointer current = first;
    while (current != nullptr) {
        out << current->data.getPlaylistName() << " ";
        current = current->next;
    }
}


int LinkedList::search(Playlist dataVal) {
    int loc;
    LinkedList::NodePointer tempP = first;
    for (loc = 0; loc < mySize; loc++)
        if (tempP->data.getPlaylistName() == dataVal.getPlaylistName())
            return loc;
        else
            tempP = tempP->next;
    return -1;
}

Playlist LinkedList::get(int index) {
    NodePointer ptr = first;
    if (index >= mySize) {
        cerr << "Index bigger than size" << endl;
        exit(1);
    }

    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }

    return ptr->data;
}

void LinkedList::reverse() {
    NodePointer prevP = nullptr, currentP = first, nextP;
    while (currentP != nullptr) {
        nextP = currentP->next;
        currentP->next = prevP;
        prevP = currentP;
        currentP = nextP;
    }
    first = prevP;       // new head of (reversed) linked LinkedList
}

ostream& operator<<(ostream& out, const LinkedList& aLinkedList) {
    aLinkedList.display(out);
    return out;
}
