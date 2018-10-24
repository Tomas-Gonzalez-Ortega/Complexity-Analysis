/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #9 lab09 The Linked Priority Queue ADT
 * Description: A generic linked structured Priotity Queue ADT header file named LinkedQueue. With the following functionalities:
 1. A constructor, LinkedQueue(), to create an empty queue.
 2. A destructor, ~LinkedQueue(), to free the queue memory.
 3. A function to insert a new element at the end of the queue:void insert(T newElement).
 4. A function to delete and return the element at the front of the queue: T remove(); this function throws a runtime-error exception.
 5.A function to check if the queue is empty: bool isEmpty().
 Assume the priority of an element is identified by an integer ranged from 1 to 5 where smaller integers show higher priorities.  
 * @version Copyright © 2017-11-30 All rights reserved. Langara College
 */

#ifndef LinkedQueue_h
#define LinkedQueue_h
#include <stdexcept>
using namespace std;


template<typename T>
class Node {
    
public:
    
    int priority;
    T element;
    Node<T> *next;
    
    // no-arg node constructor to create a node
    Node() {
        next = nullptr;
    }
    
    /**
     argumented generic node constructor to create a node with a specific element
     @param element the actual element we want to pass to the next node
     @param priority the actual priority set into the Node
     */
    Node(T element, int priority) {
        this->element = element;
        this->priority = priority;
        next = nullptr;
    }
};

template<typename T>
class LinkedQueue {
    
public:
    // No-arg constructor to create an empty Linked Queue
    LinkedQueue();
    
    // Linked Queue destructor
    ~LinkedQueue();
    
    /**
     Inserts a new element in the head element of the Linked Queue
     @param newElement the actual element we want to enqueue
     @param priority the integer value from 1 to 5 to determine the priority
     */
    void insert(T newElement, int priority) throw (runtime_error);
    
    /**
     Removes the tail element in the queue - throws a run time error if the queue is empty
     @return the queue without the element removed
     */
    T remove() throw (runtime_error);
    
    /**
     Checks if the Linked Queue is empty
     @return true if the Linked Queue is empty
     @return false if at least 1 element is contained
     */
    bool const isEmpty();
    
    Node<T> *front;
    Node<T> *rear;
    
private:
    int size;
};

#endif /* LinkedQueue_h */
