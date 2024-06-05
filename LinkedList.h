#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Todo.h"

using namespace std;

template <typename T> class LinkedList
{
    private:
        struct Node
        {
            Todo *todo; // node would be sorted by date of todo.
            Node *next;
            Node *prev;
        };

        Node *head; // pointer to head of linkedlist
        Node *tail; // pointer to tail (end) of linkedlist
        
    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        ~LinkedList();

        void appendNode(Todo<T> *);
        void editNode();
        void searchNode();
        void deleteNode(T);
        void insertNode(Todo<T> *); // insert a todo to the list.
        void displayNode() const;
};

#endif