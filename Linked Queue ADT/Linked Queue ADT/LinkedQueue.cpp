/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #9 lab09 The Linked Queue ADT
 * Description: A generic linked structured Queue ADT implementation for the LinkedQueue header file withh the following functionalities:
 1. A constructor, LinkedQueue(), to create an empty queue.
 2. A destructor, ~LinkedQueue(), to free the queue memory.
 3. A function to insert a new element at the end of the queue:void insert(T newElement).
 4. A function to delete and return the element at the front of the queue: T remove(); this function throws a runtime-error exception.
 5.A function to check if the queue is empty: bool isEmpty().
 * @version Copyright © 2017-11-30 All rights reserved. Langara College
 */

#include "LinkedQueue.h"
#include <iostream>

// No-arg constructor to create an empty Linked Queue
template<typename T>
LinkedQueue<T>::LinkedQueue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

// Queue destructor
template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    while(front->next != NULL) {
        rear = front;
        delete rear;
    }
    rear = front;
    size = 0;
    delete front;
}

/**
 Inserts a new element in the head element of the Linked Queue
 @param newElement the actual element we want to enqueue
 */
template<typename T>
void LinkedQueue<T>::insert(T newElement) {
    if(rear == size - 1)
        cout << "Out of bounds index error" << endl;
    else
        if(front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else
            rear = rear + 1;
    T element[rear] = newElement;
}

/**
 Removes the tail element in the queue - throws a run time error if the queue is empty
 @return the queue without the element removed
 */
template<typename T>
T LinkedQueue<T>::remove() throw (runtime_error) {
    if(isEmpty())
        throw runtime_error("No elements in the stack");
    T it = front->next->element;  // Store dequeued value
    Node<T> *tempNode = front->next; // Hold dequeued link
    front->next = tempNode->next;       // Advance front
    if(rear == tempNode) rear = front; // Dequeue last element
        delete tempNode;                    // Delete
    size --;
    return it;                       // Return element value
}

/**
 Checks if the Linked Queue is empty
 @return true if the Linked Queue is empty
 @return false if at least 1 element is contained
 */
template<typename T>
bool const LinkedQueue<T>::isEmpty() {
    return (size != 0);
}

/**
 Sorts a list of integers in the range [0, n) in ascending order and then prints the results
 @param inputList the list of elements we want to sort
 @param size the size of the list
 @param n the range of the elements in the list
 */
void radixSort(int inputList[], int size, int n = 1000) {
    // First finds the maximum value among the list
    int max = inputList[0];
    for (int i = 1; i < size; i++)
        if(inputList[i] > max)
            max = inputList[i];
    
    // Then we try count sorting on every number
    for (int index = 1; max/index > 0; index *= 10) {
        int i; // index
        int output[n]; // output
        int count[10] = {0};
        
        // Stores count of occurrences in count[]
        for (i = 0; i < size; i++)
            count[(inputList[i] / n) % 10]++;
        
        // Changes count[i], now it contains the actual position of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        
        // Builds the output array
        for (i = size - 1; i >= 0; i--) {
            output[count[(inputList[i] / n) % 10] - 1] = inputList[i];
            count[(inputList[i] / n) % 10]--;
        }
        
        // Copies the output array into inputList[i], sorting numbers according to current digit
        for (i = 0; i < size; i++)
            inputList[i] = output[i];
        
        // Prints
        for (int i = 0; i < size; i++)
            cout << inputList[i] << " ";
        cout << endl;
    }
}
