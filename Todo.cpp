#include <iostream>
#include "Todo.h"

using namespace std;

template <typename T> Todo<T>::Todo()
{
    description = "";
    isCompleted = false;
    date = "0/0/0";
}