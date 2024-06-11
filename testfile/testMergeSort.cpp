#include <iostream>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int value;
        Node *prev;
        Node *next;

        Node()
        {
            value = 0;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node *head;
    Node *tail;

public:
    LinkedList();
    ~LinkedList();
    void appendNode();
    void displayNode();
    void sortList();
};

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList()
{
    Node *nodePtr;
    Node *nextNode;

    nodePtr = head;

    while (nodePtr)
    {
        if (nodePtr->next)
        {
            nextNode = nodePtr->next;
        }

        delete nodePtr;
        nodePtr = nextNode;
    }
}

void LinkedList::appendNode()
{
    Node *newNode = new Node;
    Node *nodePtr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        nodePtr = head;

        while (nodePtr)
        {
            nodePtr = nodePtr->next;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::displayNode()
{
    Node *nodePtr = head;

    while(nodePtr)
    {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

void LinkedList::sortList()
{

}

int main()
{

    return 0;
}
