#include <iostream>
#include <Timer.h>

#include <vector>
#include <array> // doesn't have push_back and push_front
#include <list>
#include <forward_list>
#include <deque>


void start_PushFront_Test(){

    std::vector<int> vector;
    //std::array<int,2000000> array;
    std::list<int> list;
    std::forward_list<int> f_list;
    std::deque<int> deque;


    std::cout<<" - Push_Front (2 million elements):\n";

// Vector doesn't have Push_Front
// 2 million items in 700 seconds
    std::cout<<"Vector (200k because it works for a long time): ";
    // Use insert (no Push_Front)
    {
        Timer timer;
        for (int i = 0; i < 200000; ++i) {
            vector.insert(vector.begin(),i);
        }
    }

    std::cout<<"List: ";
    {
        Timer timer;
        for (int i = 0; i < 2000000; ++i) {
            list.push_front(i);
        }
    }

    std::cout<<"List: ";
    {
        Timer timer;
        for (int i = 0; i < 2000000; ++i) {
            f_list.push_front(i);
        }
    }

    std::cout<<"Deque: ";
    {
        Timer timer;
        for (int i = 0; i < 2000000; ++i) {
            deque.push_front(i);
        }
    }

}
