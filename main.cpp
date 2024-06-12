#include <iostream>
#include "Todo.h"
#include "Todo.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

void menu() // function to print menu
{
    cout << "1: insert new Todo" << endl
         << "2: edit Todo" << endl
         << "3: search Todo" << endl
         << "4: delete Todo" << endl
         << "5: change Todo status" << endl
         << "6: display all Todo" << endl
         << "7: end program" << endl
         << endl;
}

int main()
{
    bool isRunning = true; // if false would end the program

    LinkedList<int> todoProgram;

    while (isRunning)
    {
        int option;

        bool validInput = false;

        while (!validInput) // input validation for menu
        {
            try
            {
                menu();
                cin >> option;
                cout << endl;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    throw runtime_error("ERROR: Invalid Option");
                }
                else
                {
                    validInput = true;
                }
            }
            catch (const exception &e)
            {
                cerr << e.what() << endl
                     << endl;
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
            cout << "enter Todo id: ";
            cin >> id;
            cout << endl;
            todoProgram.changeStatus(id);
            break;
        case 6:
            todoProgram.displayNode();
            break;
        case 7:
            isRunning = false;
            break;
        default:
            break;
        }
    }

    return 0;
}