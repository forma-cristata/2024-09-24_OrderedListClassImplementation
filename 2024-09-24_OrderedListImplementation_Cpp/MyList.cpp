//
// Created by frisk on 9/14/2024.
//

#include "MyList.h"
#include <iostream>
namespace MyListNS
{
    template<typename T>
    size_t MyList<T>::getCount() const {return size;}
    template<typename T>
        size_t MyList<T>::getCapacity() const {
        return capacity;
    };

    //T& operator[](size_t index);
    //const T& operator[](size_t index) const;
    //explicit MyList(const T items[] = {});
    template<typename T>
        T& MyList<T>::operator[](size_t index)
    {
        if(index >= 0 && index < size)
        {
            return items[index];
        }
        throw std::out_of_range("index out of range");
    }

    //Constructor TODO // How do you create a constructor?

    template<typename T>
        void MyList<T>::insert(T item)
    {
        insert(size, item);
    }

    template<typename T>
        void MyList<T>::insert(int index, T item)
    {
        ++size;
        /*if (index==0)
        {
            items = [];
        }*/
        if(index < 0 || index > size)
        {
            //TODO throw new exception
        }
        if (size > capacity)
        {
            grow();
        }
        for(int i = capacity - 1; i >= index; i--)
        {
            items[i] = items[i-1];
        }
        items[index] = item;
    }

    template<typename T>
        T MyList<T>::read(int index)
    {
        if(index < 0 || index > size)
        {
            //TODO throw exception
        }

        return items[index];//TODO T is not being specified as an integer. aagghhh
    }
    template<typename T>
        int MyList<T>::search(T match)
    {
        for(int i = 0; i < size; i++)
        {
            int element = items[i];
            //TODO items[i] is a pointer.  how do I go about this?
            if(element == match)
            {
                return i;
            }
        }
        return -1;
    }
    template<typename T>
        void MyList<T>::grow()
    {
        //TODO capacity is not re-evaluating to the size of the array
        capacity = capacity == 0 ? 1 : capacity * 2;
        T* tempArray = new T[capacity];

        for(int i = 0; i < capacity; i++)
        {
            tempArray[i] = items[i];
        }
        delete[] items; //This deletes the old array
        items = tempArray;

    }


    template<typename T>
        bool MyList<T>::remove(T item)
    {
        const int index = search(item);

        if(index != -1)
        {
            removeAt(index);
            return true;
        }
        return false;
    }
    template<typename T>
        void MyList<T>::removeAt(const int index)
    {
        if(index < 0 || index >= size)
        {
            //TODO throw new index out of range exception
        }

        for(int i = index; i < capacity - 1; i++)
        {
            items[i] = items[i + 1];
        }
        if(--size < capacity / 4)
        {
            shrink();
        }
    }

    template<typename T>
        void MyList<T>::shrink()
    {
        capacity = capacity / 2;
        T* tempArray = new T[capacity];

        for(int i = 0; i < capacity; i++)
        {
            tempArray[i] = items[i];
        }
        delete[] items;
        items = tempArray;
    }
    template<typename T>
        void MyList<T>::clear()
    {
        items = {};
    }
    template<typename T>
        std::string MyList<T>::toString() const
    {
        std::string x;
        for(int i = 0; i < size-1; i++)
        {
            x += std::to_string(items[i]) + " ";
        }
        return x;

    }

    template class MyList<int>;
}

//TODO to string() method






