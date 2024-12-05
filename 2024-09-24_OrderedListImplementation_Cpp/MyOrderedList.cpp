//
// Created by frisk on 9/21/2024.
//

#include "MyOrderedList.h"

namespace MyListNS
{
template <typename T>
    void MyOrderedList<T>::insert(int index, T item)
{
    throw std::logic_error("Ordered lists can only add elements to their designated positions.");
}

template <typename T>
    void MyOrderedList<T>::insert(T item)
{
    if (this->size + 1 >= this->capacity)
    {
        this->grow();
    }

    int left = 0;
    int right = this->size - 1;
    int insertIndex = this->size;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        int comparison = this->items[mid] > item ? 1 : -1;
        comparison = this->items[mid] == item ? 0 : comparison;
        switch(comparison)
        {
        case 0:
            right = left - 1;
            insertIndex = mid;
            break;
        case 1:
            right = mid-1;
            insertIndex = mid;
            break;
        default:
            left = mid + 1;
        }
    }

    for(int i = this->size-1; i > insertIndex; --i)
    {
        this->items[i] = this->items[i-1];
    }

    this->items[insertIndex] = item;
    ++this->size;
}
template <typename T>
    int MyOrderedList<T>::search(T match)
{
    int left = 0;
    int right = this->size - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        int comparison = this->items[mid] > match ? 1 : -1;
        comparison = this->items[mid] == match ? 0 : comparison;
        switch(comparison)
        {
        case 0:
            left = mid;
            return left;
        case -1:
            left = mid + 1;
            break;
        case 1:
            right = mid - 1;
            break;
        }

    }
    return -1;
}


template class MyOrderedList<int>;

}






