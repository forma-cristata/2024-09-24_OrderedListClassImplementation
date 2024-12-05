//
// Created by frisk on 9/14/2024.
//
//
// Created by frisk on 9/14/2024.
//

#include "MyList.h"
#include "MyOrderedList.h"
#include <iostream>

void testOrderedList();
void testList();
int main()
{
    //TestList();
    testOrderedList();
    return 0;
}

void testOrderedList()
{

    std::cout<<"***Testing My Ordered List***"<<std::endl<<std::endl;
    const size_t size = 10;
    MyListNS::MyOrderedList<int> my_ordered_list(0);
    std::cout << "Numbers before ordering: ";
    for(int i = 0; i<size; i++)
    {
        size_t randNum = rand() % 100; //800-275-6401

        int x = my_ordered_list.search(randNum);
        while(x != -1)
        {
            randNum = rand() % 100;
            x = my_ordered_list.search(randNum);
        }
        my_ordered_list.insert(randNum);
        std::cout<<randNum<<" ";
    }

    std::cout<<std::endl;
    std::cout << "Random numbers after insertion: " << my_ordered_list.toString() << std::endl<<std::endl;

    try
    {
        my_ordered_list.insert(2, 10);
    }
    catch(std::exception e){std::cout<<"Exception thrown."<<std::endl<< e.what() <<std::endl;}


}

void testList()
{

    std::cout<<"***Testing My List***"<<std::endl;
    MyListNS::MyList<int> my_list(0);

    for(int i = 0; i < 6; i ++)
    {
        my_list.insert(i);
    }
    std::cout<<my_list.toString()<<std::endl;

    int secondElement = my_list.read(2);
    std::cout<< "Read 2nd Element: " << secondElement <<std::endl;

    std::cout << "Index of element equal to 3: " << my_list.search(3) << std::endl;

    my_list.insert(55);
    std::cout << "After appending 55 to the end of the array: ";
    std::cout << my_list.toString() << std::endl;

    my_list.insert(4, 16);
    std::cout << "After inserting 16 in the fifth position: ";
    std::cout << my_list.toString() << std::endl;


    my_list.remove(3);
    std::cout << "After removing any item equal to 3: ";
    std::cout << my_list.toString() << std::endl;


    my_list.removeAt(4);
    std::cout << "After removing the 5th element: ";
    std::cout << my_list.toString() << std::endl;



}



