#ifndef TODO_H
#define TODO_H

#include <iostream>
using namespace std;

template <typename T>
class Todo
{
private:
    static int todoCount; // variable use keep track if todo instances
    int id;
    string description; // task for that Todo
    bool isCompleted;   // status on whether or not that Todo is completed
    string date;        // date for that Todo
    int day, month, year;

    void dateParser(string &); // split datestring into day month and year

public:
    Todo(); // Default Constructor
    Todo(string, string);
    void setID(int);                  // ID setter
    int getID() const;             // getter for ID
    void setDescription(string);   // setter for description
    string getDescription() const; // description getter
    void setIsCompleted(bool);     // isCompleted setter
    bool getIsCompleted() const;   // isCompleted getter
    void setDate(string);          // date setter
    string getDate() const;        // date getter
    void displayTodoInfo() const;  // display full todo info
    int getYear() const;           // getter for year
    int getMonth() const;          // getter for month
    int getDay() const;            // getter for days

    bool operator>(const Todo &) const; // overloaded > operator to compare date Todos
    bool operator<(const Todo &) const; // overloaded > operator to compare date Todos
};

#endif