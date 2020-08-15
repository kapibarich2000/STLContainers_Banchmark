#include <iostream>
#include <Timer.h>

#include <vector>
#include <list>
#include <forward_list>
#include <deque>

#define Number_of_deletions 2000000
#define Number_of_deletions_for_F_list 20000


void start_PopBack_Test(){

    std::vector<int> vector;
    std::list<int> list;
    std::forward_list<int> f_list;
    std::deque<int> deque;

    for (int i = 0; i < Number_of_deletions; ++i) {
        vector.push_back(i);
        list.push_back(i);
        deque.push_back(i);
    }
    for (int i = 0; i < Number_of_deletions_for_F_list; ++i) {
        f_list.push_front(i);
    }
    f_list.reverse();


    std::cout<<"\n - Pop_Back (2 million elements):\n";


    std::cout<<"Vector: ";
    {
        Timer timer;
        while (!vector.empty())
            vector.pop_back();
    }
    // Vector is So fast, because vector doesn't make vector.shrink_to_fit() and doesn't clean the data;
    // It just shifts the end pointer down one position
    // vector.data() + 2000000 - it is possible to access "deleted data"


    std::cout<<"List: ";
    {
        Timer timer;
        while(!list.empty())
            list.pop_back();
    }


    std::cout<<"F_List (20k because it works for a long time): ";
    //  doesn't have pop.back() -> Use erase_after and some algorithm
    {
        Timer timer;
        auto ItLast_f_list = f_list.before_begin();
        auto It_Penultimate = f_list.before_begin();
        auto It = f_list.begin();
        while (!f_list.empty()) {
            ItLast_f_list = f_list.before_begin();
            It_Penultimate = ItLast_f_list;

            for (It = f_list.begin(); It != f_list.end(); ++It) {
                It_Penultimate = ItLast_f_list;
                ItLast_f_list = It;
            }
            f_list.erase_after(It_Penultimate);
        }
    }


    std::cout<<"Deque: ";
    {
        Timer timer;
        while (!deque.empty())
            deque.pop_back();
    }
    // Deque wastes the time to deleted unused reserved data
}