#include <iostream>
#include <Timer.h>

#include <vector>
#include <list>
#include <forward_list>
#include <deque>

#define Number_of_deletions 20000000

#define Number_of_deletions_for_vector 200000

void start_PopFront_Test(){

    std::vector<int> vector;
    std::list<int> list;
    std::forward_list<int> f_list;
    std::deque<int> deque;

    for (int i = 0; i < Number_of_deletions_for_vector; ++i) {
        vector.push_back(i);
    }

    for (int i = 0; i < Number_of_deletions; ++i) {
        list.push_back(i);
        deque.push_back(i);
        f_list.push_front(i);
    }
    f_list.reverse();

    std::cout<<"\n - Pop_Front (2 million elements):\n";
    std::cout<<"Vector ("<<Number_of_deletions_for_vector<<" because it works for a long time): "; // default 200k
    {
        Timer timer;
        while (!vector.empty())
            vector.erase(vector.begin());
    }

    std::cout<<"List: ";
    {
        Timer timer;
        while(!list.empty())
            list.pop_front();
    }

    std::cout<<"F_List: ";     //  doesn't have push.back() -> Use insert and some algorithm

    {
        Timer timer;
        while (!f_list.empty())
           f_list.pop_front();
    }

    std::cout<<"Deque: ";
    {
        Timer timer;
        while (!deque.empty())
            deque.pop_front();
    }
}