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
            Todo todo;
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

};

#endif