/**
 * @author Name: Tomas Gonzalez ID: 100266942.
 * CPSC 1160 Assignment #9 lab09 The Linked Priority Queue ADT
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
#include "LinkedQueue.h"
using namespace std;

int main() {
    int choice, item, priority;
    LinkedQueue<int> intLinkedQueue;
    do {
        cout << "1.Insert\n";
        cout << "2.Remove\n";
        cout << "3.Display\n";
        cout << "4.Quit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the item to be added in the queue : ";
                cin >> item;
                cout << "Please enter the priority of the item : ";
                cin >> priority;
                intLinkedQueue.insert(item, priority);
                break;
            case 2:
                intLinkedQueue.remove();
                break;
            case 3:
                // TO DO
                break;
            case 4:
                break;
            default :
                cout << "Please enter a right option\n";
        }
    }
    while(choice != 4);
    return 0;
}



   
