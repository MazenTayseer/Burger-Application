#include <iostream>
#include "Queue.h"

using namespace std;

//--- Definition of Queue constructor
Queue::Queue(int numElements)
    : myFront(0), myBack(0), myCapacity(numElements)
{
    // allocate array of this capacity
    myArray = new (nothrow) QueueElement[myCapacity];
    if (myArray == 0) {
        cerr << "error";
        exit(0);
    }
}

////--- Definition of Dynamic Queue destructor
Queue::~Queue()
{
    delete (myArray);
}

//--- Definition of empty()
bool Queue::empty() const
{
    return (myFront == myBack);
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement& value)
{
    int newBack = (myBack + 1) % myCapacity;
    if (newBack != myFront)     // queue isn't full
    {
        myArray[myBack] = value;
        myBack = newBack;
    }
    else
    {
        cerr << "*** Queue full -- can't add new value ***\n"
            "Must increase value of QUEUE_CAPACITY in Queue.h\n";
        exit(1);
    }
}

//--- Definition of display()
void Queue::display(ostream& out) const
{
    int index = 1;
    for (int i = myFront; i != myBack; i = (i + 1) % myCapacity) {
        out << index << ". " << myArray[i].getName() << " - " << myArray[i].getDuration() << endl;
        index += 1;
    }
}

//--- Definition of output operator
ostream& operator<< (ostream& out, const Queue& aQueue) {
    aQueue.display(out);
    return out;
}

//--- Definition of front()
QueueElement Queue::front() const
{
    if (!empty())
        return (myArray[myFront]);
    else
    {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage;
        return garbage;
    }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
    if (!empty())
        myFront = (myFront + 1) % myCapacity;
    else
    {
        cerr << "*** Queue is empty -- "
            "can't remove a value ***\n";
        exit(1);
    }
}
