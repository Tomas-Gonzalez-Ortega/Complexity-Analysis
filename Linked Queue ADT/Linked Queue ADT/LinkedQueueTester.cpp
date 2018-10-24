/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #9 lab09 The Linked Queue ADT
 * Description: A generic linked structured Queue ADT main testing the following functionalities:
 1. A constructor, LinkedQueue(), to create an empty queue.
 2. A destructor, ~LinkedQueue(), to free the queue memory.
 3. A function to insert a new element at the end of the queue:void insert(T newElement).
 4. A function to delete and return the element at the front of the queue: T remove(); this function throws a runtime-error exception.
 5.A function to check if the queue is empty: bool isEmpty().
 * @version Copyright © 2017-11-30 All rights reserved. Langara College
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "LinkedQueue.h"
using namespace std;

int main() {
    // Create a linked int queue
    LinkedQueue<int> intLinkedQueue;
    for (int i = 0; i < 10; i++)
        intLinkedQueue.insert(i);
    while (!intLinkedQueue.isEmpty())
        cout << intLinkedQueue.remove() << " ";
    cout << endl;
    
    // Create a linked string stack
    LinkedQueue<string> stringLinkedQueue;
    stringLinkedQueue.insert("Naoko");
    stringLinkedQueue.insert("Karina");
    stringLinkedQueue.insert("Tarra");
    while (!stringLinkedQueue.isEmpty())
        cout << stringLinkedQueue.remove() << " ";
    cout << endl;
    
    LinkedQueue<int> intArrayLinkedQueue;
    int inputList[] = {5, 17, 12, 9, 44, 27};
    int size = 5;
    int n = 1000;
    intArrayLinkedQueue.radixSort(inputList, size, n);
    
    return 0;
}
