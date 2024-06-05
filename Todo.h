#ifndef TODO_H
#define TODO_H

#include <iostream>
using namespace std;

template <typename T>
class Todo
{
private:
    static int todoCount;
    int id;
    string description;
    bool isCompleted;
    string date;
    int day, month, year;

    void dateParser();

public:
    Todo(); // Default Constructor
    Todo(string, string);
    int getID() const; // no setter for id since it is automatically assigned on object instantiation.
    void setDescription(string); // setter for description
    string getDescription() const; // description getter
    void setIsCompleted(bool); // isCompleted setter
    bool getIsCompleted() const; // isCompleted getter
    void setDate(string); // date setter
    string getDate() const; // date getter
    void displayTodoInfo() const; // display full todo info
    int getYear() const;  // getter for year
    int getMonth() const; // getter for month
    int getDay() const;   // getter for days

    bool operator>(const Todo &) const;
    bool operator<(const Todo &) const;
};

#endif