/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #9 lab09 The Linked Priority Queue ADT
 * Description: A generic linked structured Priority Queue ADT implementation for the LinkedQueue header file withh the following functionalities:
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
    while(front->next != nullptr) {
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
 @param priority the priority of the element to be inserted into the queue
 */
template<typename T>
void LinkedQueue<T>::insert(T newElement, int priority) throw (runtime_error) {
    if (rear == front - 1)
        throw runtime_error("Error: Queue is currently full");
    else {
        Node<T>* newNode = new Node<T>(newElement, priority);
        Node<T>* tmp = front->next;
        Node<T>* current = front;
        while (newNode->priority < tmp->priority && tmp->next != nullptr) {
            if (rear == nullptr)
                rear = front;
            current = tmp;
            tmp = tmp->next;
            front = newNode;
        }
    }
}

/**
 Removes the tail element in the queue - throws a run time error if the queue is empty
 @return the queue without the element removed
 */
template<typename T>
T LinkedQueue<T>::remove() throw (runtime_error) {
    if (isEmpty())
        throw runtime_error("Error: the Queue is currently empty");
    else {
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        T element = temp->element;
        delete temp;
        size--;
        return element;
    }
}

/**
 Checks if the Linked Queue is empty
 @return true if the Linked Queue is empty
 @return false if front and rear points a null pointer value
 */
template<typename T>
bool const LinkedQueue<T>::isEmpty() {
    return (front == nullptr && rear == nullptr);
}


