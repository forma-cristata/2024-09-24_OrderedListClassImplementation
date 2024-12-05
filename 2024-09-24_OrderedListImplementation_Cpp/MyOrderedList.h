//
// Created by frisk on 9/21/2024.
//

#ifndef MYORDEREDLIST_H
#define MYORDEREDLIST_H
#include "MyList.h"



namespace MyListNS{

    template <typename T>
        concept Numeric = std::is_arithmetic_v<T>;
    template <typename T>
    class MyOrderedList : public MyList<T>
    {
      public:
        static void insert(int index, T item);
        void insert(T item);
        int search(T match);


    };


}



#endif //MYORDEREDLIST_H
