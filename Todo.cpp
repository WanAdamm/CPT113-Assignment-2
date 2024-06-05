#include <iostream>
#include <sstream>
#include "Todo.h"

using namespace std;

template <typename T>
Todo<T>::Todo()
{
    id = todoCount;
    description = "";
    isCompleted = false;
    date = "00/00/0000"; // dd/mm/yyyy/ tttt (time in military hours)

    dateParser(date);

    todoCount++;
}

template <typename T>
void Todo<T>::dateParser()
{
    string dayString, monthString, yearString;

    // date processing
    istringstream dateStream(date);
    getline(dateStream, dayString, '/');
    getline(dateStream, monthString, '/');
    getline(dateStream, yearString, '/');

    day = stoi(dayString);
    month = stoi(monthString);
    year = stoi(yearString);
}

template <typename T>
int Todo<T>::getID() const
{
    return id;
}

template <typename T>
void Todo<T>::setDescription(string _description)
{
    description = _description;
}

template <typename T>
string Todo<T>::getDescription() const
{
    return description;
}

template <typename T>
void Todo<T>::setIsCompleted(bool _isCompleted)
{
    isCompleted = _isCompleted;
}

template <typename T>
bool Todo<T>::getIsCompleted() const
{
    return isCompleted;
}

template <typename T>
void Todo<T>::setDate(string _date)
{
    date = _date;
}

template <typename T>
string Todo<T>::getDate() const
{
    return date;
}

template <typename T>
void Todo<T>::displayTodoInfo() const
{
    string status;

    if (isCompleted)
    {
        status = "completed";
    }
    else
    {
        status = "not completed";
    }

    cout << "id: " << id << endl
         << "task: " << description << endl
         << "status: " << isCompleted << endl
         << "date: " << date << endl;
}

template <typename T>
int Todo<T>::getYear() const
{
    return year;
}

template <typename T>
int Todo<T>::getMonth() const
{
    return month;
}

template <typename T>
int Todo<T>::getDay() const
{
    return day;
}

template <typename T>
bool Todo<T>::operator>(const Todo &other) const
{
    if (this->year != other->getYear())
    {
        return this->year > other.getYear();
    }
    else if (this->month != other.getMonth)
    {
        return this->month > other.getMonth();
    }
    else
    {
        return this->day > other.getDay();
    }
}