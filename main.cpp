#include <iostream>
#include "Todo.h"
#include "Todo.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

void menu()
{
    cout << "1: insert new Todo" << endl
         << "2: edit Todo" << endl
         << "3: search Todo" << endl
         << "4: delete Todo" << endl
         << "5: display all Todo" << endl
         << "6: end program" << endl
         << endl;
}

int main()
{
    bool isRunning = true;

    LinkedList<int> todoProgram;

    while (isRunning)
    {
        int option;

        bool validInput = false;

        while (!validInput) // input validation for menu
        {
            menu();
            cin >> option;
            cout << endl;

            if (cin.fail())
            {
                cout << "enter a valid option!" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            else
            {
                validInput = true;
            }
        }

        int id;
        switch (option)
        {
        case 1:
            todoProgram.insertNode();
            break;
        case 2:
            cout << "enter Todo id: ";
            cin >> id;
            cout << endl;
            todoProgram.editNode(id);
            break;
        case 3:
            cout << "enter Todo id: ";
            cin >> id;
            cout << endl;
            todoProgram.searchNode(id);
            break;
        case 4:
            cout << "enter Todo id: ";
            cin >> id;
            cout << endl;
            todoProgram.deleteNode(id);
            break;
        case 5:
            todoProgram.displayNode();
            break;
        case 6:
            isRunning = false;
            break;
        default:
            break;
        }
    }

    return 0;
}