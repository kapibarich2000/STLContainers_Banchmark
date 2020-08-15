#include <iostream>
#include <Timer.h>

#include <vector>
#include <array> // doesn't have push_back, push_front and insert
#include <list>
#include <forward_list>
#include <deque>

#define Number_of_inserts 2000000

#define Number_of_inserts_for_vector 200000

void start_PushFront_Test(){

    std::vector<int> vector;
    std::list<int> list;
    std::forward_list<int> f_list;
    std::deque<int> deque;


    std::cout<<" - Push_Front (2 million elements):\n";

// Vector doesn't have Push_Front
    // Use insert
// 2 million items in 700 seconds
    std::cout<<"Vector ("<<Number_of_inserts_for_vector<<" because it works for a long time): "; // default 200k
    {
        // due to constant displacement and re-indexing
        Timer timer;
        for (int i = 0; i < Number_of_inserts_for_vector; ++i) {
            vector.insert(vector.begin(),i);
        }
    }

    std::cout<<"List: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            list.push_front(i);
        }
    }

    std::cout<<"List: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            f_list.push_front(i);
        }
    }

    std::cout<<"Deque: ";
    {
        // Allocated additional 512 byte each time as soon as the space runs out
        // 512 byte == 128 int

        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            deque.push_front(i);

        }
    }

}
