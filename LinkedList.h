#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Todo.h"

using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        Todo<T> *todo; // node would be sorted by date of todo.
        Node *next;
        Node *prev;
    };

    Node *head; // pointer to head of linkedlist
    Node *tail; // pointer to tail (end) of linkedlist

    Todo<T> *createTodo(); // return pointer to a newTodo
public:
    LinkedList();
    ~LinkedList();
    void insertNode();          // insert a todo to the list.
    void editNode(int);         // only able to edit the task and date, enter specific id of the node that is to be edited
    void searchNode(int) const; // search by ID
    void deleteNode(int);       // delete by ID
    void displayNode() const;
};

#endif