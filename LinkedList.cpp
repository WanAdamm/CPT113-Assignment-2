#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Todo.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;

    initNode();
}

template <typename T>
void LinkedList<T>::initNode() // Initialize the LinkedList with some todo in it
{
    fstream DataFile("init.txt");

    string date, desc, token;

    getline(DataFile, token); // skip first line of file
    while(getline(DataFile, date, ','))
    {
        getline(DataFile, desc, ',');
        insertNode(desc, date);
    }
}

template <typename T>
Todo<T> *LinkedList<T>::createTodo()
{
    bool validInput = false;
    Todo<T> *newTodo = nullptr;
    cin.ignore(INT_MAX, '\n');

    while (!validInput)
    {
        try
        {
            string date, description;
            // int dateInt;

            cout << "date for task (dd/mm/yyyy): ";
            getline(cin, date);

            cout << "task: ";

            getline(cin, description);

            cout << endl;

            newTodo = new Todo<T>(description, date); // if the todo is invalid then return nothing
            validInput = true;
        }
        catch (const invalid_argument &e)
        {
            cerr << "ERROR: Can't create Todo, check your inputs." << endl
                 << endl;
        }
    }

    return newTodo;
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
        while (nodePtr != nullptr && *(newNode->todo) > *(nodePtr->todo)) // sort in ascending list
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
void LinkedList<T>::insertNode(string description, string date)
{
    Todo<T> *newTodo = new Todo<T>; // create a new todo
    newTodo->setDescription(description);
    newTodo->setDate(date);

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
        while (nodePtr != nullptr && *(newNode->todo) > *(nodePtr->todo)) // sort in ascending list
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
void LinkedList<T>::insertNode(string description, string date, int id)
{
    Todo<T> *newTodo = new Todo<T>; // create a new todo
    newTodo->setDescription(description);
    newTodo->setDate(date);
    newTodo->setID(id);

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
        while (nodePtr != nullptr && *(newNode->todo) > *(nodePtr->todo)) // sort in ascending list
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
void LinkedList<T>::editNode(int TodoID)
{
    Node *nodePtr; // to traverse list

    nodePtr = head;

    // Traverse the list until we find the node or reach the end
    while (nodePtr != nullptr && nodePtr->todo->getID() != TodoID)
    {
        nodePtr = nodePtr->next;
    }

    try
    {
        if (nodePtr == nullptr)
        {
            throw runtime_error("ERROR: No Todo with such ID found.");
        }
        else
        {
            cout << "1: edit date" << endl
                 << "2: edit task" << endl
                 << endl;

            int option;

            cin >> option;
            cout << endl;

            if (option == 1)
            {
                cout << "Enter new date: " << endl;
                string date;
                cin >> date;

                insertNode(nodePtr->todo->getDescription(), date, nodePtr->todo->getID());
                deleteNode(nodePtr->todo->getID());

                // delete nodePtr;
            }
            else if (option == 2)
            {
                cout << "Enter edited task" << endl;
                string desc;
                cin.ignore(INT_MAX, '\n');
                getline(cin, desc);
                nodePtr->todo->setDescription(desc);
            }
        }
    }
    catch (const invalid_argument &e)
    {
        cerr << "ERROR: Invalid Date" << endl
             << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl
             << endl;
    }
}

template <typename T>
void LinkedList<T>::searchNode(int TodoID) const
{
    Node *nodePtr = head; // Start at the beginning of the list

    // Traverse the list until we find the node or reach the end
    while (nodePtr != nullptr && nodePtr->todo->getID() != TodoID)
    {
        nodePtr = nodePtr->next;
    }

    try
    {
        // Check if we found the node
        if (nodePtr == nullptr)
        {
            throw runtime_error("ERROR: No Todo with such ID found.");
        }
        else
        {
            string status = "not completed";

            if (nodePtr->todo->getIsCompleted() == 1)
            {
                status = "completed";
            }

            cout << nodePtr->todo->getDescription() << endl
                 << status << endl
                 << endl;
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl
             << endl;
    }
}

template <class T>
void LinkedList<T>::deleteNode(int todoID)
{
    Node *nodePtr; // To traverse the list

    try
    {
        // If the list is empty, throw an error.
        if (!head)
        {
            throw runtime_error("ERROR: No Todo in the list yet!");
            return;
        }

        // Determine if the first node is the one.
        if (head->todo->getID() == todoID)
        {
            if (head->next)
            {
                nodePtr = head->next;
                nodePtr->prev = nullptr;
            }
            else
            {
                nodePtr = nullptr;
            }

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
                if (nodePtr->next)
                    nodePtr->next->prev = nodePtr->prev;
                if (nodePtr->prev)
                    nodePtr->prev->next = nodePtr->next;
                if (nodePtr == tail) // If the node to be deleted is the tail
                    tail = nodePtr->prev;
                delete nodePtr;
            }
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl
             << endl;
    }
}

template <typename T>
void LinkedList<T>::displayNode() const // print out all Todo
{
    try
    {
        Node *nodePtr;

        nodePtr = head;

        if (!nodePtr)
        {
            throw runtime_error("ERROR: Empty list");
        }

        while (nodePtr)
        {
            nodePtr->todo->displayTodoInfo();
            cout << endl;
            nodePtr = nodePtr->next;
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl
             << endl;
    }
}

template <typename T>
void LinkedList<T>::changeStatus(int TodoID)
{
    Node *nodePtr = new Node; // for traversal

    nodePtr = head;

    // Traverse the list until we find the node or reach the end
    while (nodePtr != nullptr && nodePtr->todo->getID() != TodoID)
    {
        nodePtr = nodePtr->next;
    }

    if (nodePtr == nullptr)
    {
        cout << "no such task found" << endl
             << endl;
    }
    else
    {
        bool status;
        cout << "0: Not Completed" << endl
             << "1: Completed" << endl
             << endl;

        cin >> status;

        nodePtr->todo->setIsCompleted(status);
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
