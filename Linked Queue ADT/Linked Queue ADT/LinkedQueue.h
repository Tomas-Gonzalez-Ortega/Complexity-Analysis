/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #9 lab09 The Linked Queue ADT
 * Description: A generic linked structured Queue ADT header file named LinkedQueue. With the following functionalities:
 1. A constructor, LinkedQueue(), to create an empty queue.
 2. A destructor, ~LinkedQueue(), to free the queue memory.
 3. A function to insert a new element at the end of the queue:void insert(T newElement).
 4. A function to delete and return the element at the front of the queue: T remove(); this function throws a runtime-error exception.
 5.A function to check if the queue is empty: bool isEmpty().
 * @version Copyright © 2017-11-30 All rights reserved. Langara College
 */

#ifndef LinkedQueue_h
#define LinkedQueue_h
#include <stdexcept>
using namespace std;

template<typename T>
class Node {
    
public:
    
    T element;
    Node<T> next;
    
    // no-arg node constructor to create a node
    Node() {
        next = nullptr;
    }
    
    /**
     argumented generic node constructor to create a node with a specific element
     @param element the actual element we want to pass to the next node
     */
    Node(T element) {
        this->element = element;
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
     */
    void insert(T newElement);
    
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
    
    /**
     Sorts a list of integers in the range [0, n) in ascending order
     @param inputList the list of elements we want to sort
     @param size the size of the list
     @param n the range of the elements in the list
     */
    void radixSort(int inputList[], int size, int n = 1000);
    
    Node<T> *front;
    Node<T> *rear;
    
private:
    int size;
};

#endif /* LinkedQueue_h */
