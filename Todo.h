#ifndef TODO_H
#define TODO_H

#include <iostream>
using namespace std;

template <typename T>
class Todo
{
private:
    static int todoCount = 0;
    int id;
    string description;
    bool isCompleted;
    string date;
    int day, month, year;

    void dateParser();

public:
    Todo();
    int getID() const; // no setter for id since it is automatically assigned on object instantiation.
    void setDescription(string);
    string getDescription() const;
    void setIsCompleted(bool);
    bool getIsCompleted() const; // isCompleted getter
    void setDate(string);
    string getDate() const;
    void displayTodoInfo() const;
    int getYear() const; // getter for year
    int getMonth() const; // getter for month
    int getDay() const; // getter for days

    bool operator >(const Todo&) const;
};

#endif