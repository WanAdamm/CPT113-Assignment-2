#include <iostream>
#include "LinkedList.h"
#include "Todo.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
Todo<T> *LinkedList<T>::createTodo()
{
    string date, description;

    cin.ignore(INT_MAX, '\n');

    cout << "date for task (dd/mm/yyyy): ";
    getline(cin, date);

    cout << "task: ";

    getline(cin, description);

    cout << endl;

    Todo<T> *newTodo = new Todo<T>(description, date);

    return newTodo;
}

template <typename T>
void LinkedList<T>::appendNode()
{
    Todo<T> *newTodo = createTodo(); // create a new todo

    Node *nodePtr;
    Node *newNode = new Node;

    newNode->todo = newTodo;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        nodePtr = tail;
        newNode->prev = nodePtr;
        nodePtr->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::insertNode()
{
    Todo<T> *newTodo = createTodo(); // create a new todo

    Node *newNode; // A new node
    Node *nodePtr; // To traverse the list

    // Allocate a new node and store newValue there.
    newNode = new Node;
    newNode->todo = newTodo;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    // If there are no nodes in the list
    // make newNode the first node
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else // Otherwise, insert newNode
    {
        // Position nodePtr at the head of list.
        nodePtr = head;
        // Skip all nodes whose value is less than newValue.
        // Value of node would be sorted in ascending order.
        while (nodePtr != nullptr && newTodo > nodePtr->todo) // TODO: fix overloading operator 
        {
            nodePtr = nodePtr->next;
        }
        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (nodePtr == head)
        {
            head = newNode;
            newNode->next = nodePtr;
            nodePtr->prev = newNode;
        }
        else if (nodePtr == nullptr)
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else // inserting in middle of list
        {
            nodePtr->prev->next = newNode; // link the previous node to a newnode since we want to insert it in the middle
            newNode->prev = nodePtr->prev; // link the newnode to previous node
            nodePtr->prev = newNode;
            newNode->next = nodePtr;
        }
    }
}

template <typename T>
void LinkedList<T>::editNode(int id)
{
    Node *nodePtr; // to traverse list

    nodePtr = head;

    cout << "1: edit date" << endl
         << "2: edit task" << endl
         << endl;

    int option;

    cin >> option;
    cout << endl;

    while (nodePtr)
    {
        if (nodePtr->todo->getID() == id)
        {
            if (option == 1)
            {
                cout << "Enter new date: " << endl;
                string date;
                cin >> date;
                nodePtr->todo->setDate(date);
            }
            else if (option == 2)
            {
                cout << "Enter edited task" << endl;
                string desc;
                cin >> desc;
                nodePtr->todo->setDescription(desc);
            }

            break;
        }
        else
        {
            nodePtr = nodePtr->next;
        }
    }

    if (nodePtr == nullptr) // TODO:rewrite in exception block
    {
        cout << "No such node found" << endl;
    }
}

template <typename T>
void LinkedList<T>::searchNode(int id) const
{
    // TODO: add functionality for searchNode
    Node *nodePtr; // traverse the list

    nodePtr = head;

    while (nodePtr->todo->getID() != id)
    {
        nodePtr = nodePtr->next;
    }

    if (nodePtr = nullptr)
    {
        cout << "no such task found" << endl
             << endl;
    }
}

template <class T>
void LinkedList<T>::deleteNode(int todoID)
{
    Node *nodePtr; // To traverse the list
    // If the list is empty, do nothing.
    if (!head)
        return;
    // Determine if the first node is the one.
    if (head->todo->getID() == todoID)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list
        nodePtr = head;
        // Skip all nodes whose value member is
        // not equal to num.
        while (nodePtr != nullptr && nodePtr->todo->getID() != todoID)
        {
            nodePtr = nodePtr->next;
        }
        // If nodePtr is not at the end of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            nodePtr->prev->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

template <typename T>
void LinkedList<T>::displayNode() const // print out all Todo
{
    Node *nodePtr;

    nodePtr = head;

    while (nodePtr)
    {
        nodePtr->todo->displayTodoInfo();
        cout << endl;
        nodePtr = nodePtr->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node *nodePtr;  // To traverse the list
    Node *nextNode; // To point to the next node
    // Position nodePtr at the head of the list.
    nodePtr = head;
    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr) // while next is not nullptr
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next; // assign nodePtr to nextPtr
        // Delete the current node.
        delete nodePtr;
        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}