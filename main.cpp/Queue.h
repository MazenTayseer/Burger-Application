#pragma once

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include "Song.h"
using namespace std;

const int QUEUE_CAPACITY = 1024;
typedef Song QueueElement;

class Queue
{
public:
    /***** Function Members *****/
    /***** Constructor *****/
    Queue(int numElements = 1024);
    /*-----------------------------------------------------------------------
     Construct a Queue object.

     Precondition:  None.
     Postcondition: An empty Queue object has been constructed; myFront
     and myBack are initialized to -1 and myArray is an array with
     QUEUE_CAPACITY elements of type QueueElement.
     ----------------------------------------------------------------------*/
     /***** Destructor *****/
    ~Queue();
    /*-----------------------------------------------------------------------
//     Class destructor
//
//     Precondition:  None
//     Postcondition: The dynamic array in the queue has been deallocated.
//     ------------------------------------------------------------------------*/

    bool empty() const;
    /*-----------------------------------------------------------------------
     Check if queue is empty.

     Precondition: None.
     Postcondition: True is returned if the queue is empty and false is
     returned otherwise.
     ----------------------------------------------------------------------*/

    void enqueue(const QueueElement& value);
    /*-----------------------------------------------------------------------
     Add a value to a queue.

     Precondition:  value is to be added to this queue.
     Postcondition: value is added to back of queue provided there is space;
     otherwise, a queue-full message is displayed and execution is
     terminated.
     -----------------------------------------------------------------------*/

    void display(ostream& out) const;
    /*-----------------------------------------------------------------------
     Output the values stored in the queue.

     Precondition:  ostream out is open.
     Postcondition: Queue's contents, from front to back, have been output
     to out.
     -----------------------------------------------------------------------*/

    QueueElement front() const;
    /*-----------------------------------------------------------------------
     Retrieve value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue is returned, unless queue is
     empty; in that case, an error message is displayed and a "garbage
     value" is returned.
     ----------------------------------------------------------------------*/

    void dequeue();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).

     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless queue
     is empty; in that case, an error message is displayed and
     execution is terminated.
     ----------------------------------------------------------------------*/

private:
    /***** Data Members *****/
    int myFront,
        myBack,
        myCapacity;
    QueueElement* myArray;
}; // end of class declaration

//------ Prototype of output operator
ostream& operator<< (ostream& out, const Queue& aList);


#endif /* Queue_h */
