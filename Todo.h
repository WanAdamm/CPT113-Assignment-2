#ifndef TODO_H
#define TODO_H

#include <iostream>
using namespace std;

template <typename T> class Todo
{
    private:
        string description;
        bool isCompleted;
        string date;
    public:
        Todo();
        void setDescription();
        string getDescription() const;
        void setIsCompleted();
        bool getIsCompleted() const;
        void setDate();
        string getDate() const;
};

#endif