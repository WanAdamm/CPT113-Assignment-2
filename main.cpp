#include <iostream>
#include "Todo.h"
#include "Todo.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

void menu()
{
    cout << "1: append new Todo" << endl
         << "2: insert new Todo" << endl
         << "3: edit Todo" << endl
         << "4: search Todo" << endl
         << "5: delete Todo" << endl
         << "6: display all Todo" << endl
         << endl;
}

int main()
{
    bool isRunning = true;

    LinkedList<int> todoProgram;

    while (isRunning)
    {
        menu();

        int option;
        cin >> option;

        int id;
        switch (option)
        {
        case 1:
            todoProgram.appendNode();
            break;
        case 2:
            todoProgram.insertNode();
            break;
        case 3:
            cout << "enter Todo id: ";
            cin >> id;
            todoProgram.editNode(id);
            break;
        case 4:
            cout << "enter Todo id: ";
            cin >> id;
            todoProgram.searchNode(id);
            break;
        case 5:
            cout << "enter Todo id: ";
            cin >> id;
            todoProgram.deleteNode(id);
            break;
        case 6:
            todoProgram.displayNode();
            break;
        case 7:
            isRunning = false;
            break;        
        default:
            menu();
            break;
        }
    }

    return 0;
}