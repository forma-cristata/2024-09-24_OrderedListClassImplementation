//
// Created by frisk on 9/14/2024.
//

#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>


//T is a template parameter that represents a type
//Essentially whatever data type the user wants to use your list for
namespace MyListNS
{
    template<typename T>
    class MyList
    {
    protected:
        T* items;
        size_t size = 0;
        size_t capacity = size;

    public:
        MyList(const size_t theSize)
        {
            size = theSize;
            capacity = theSize;
            items = new T[capacity];
        }
        size_t getCount() const;
        size_t getCapacity() const;


        T& operator[](size_t index);

        //T& operator[](size_t index);
        //const T& operator[](size_t index) const;
        //explicit MyList(const T items[] = {});


        void insert(T item);

        void insert(int index, T item);

        T read(int index);

        int search(T match);

        void grow();

        bool remove(T item);

        void removeAt(const int index);

        void shrink();

        void clear();
        std::string toString() const;

        //TODO to string() method

    };
}


#endif //MYLIST_H
