#include <iostream>
#include <Timer.h>

#include <vector>
#include <array> // doesn't have push_back, push_front and insert
#include <list>
#include <forward_list>
#include <deque>

#define Number_of_inserts 2000000

void start_PushBack_Test(){

    std::vector<int> vector;
    std::list<int> list;
    std::forward_list<int> f_list;
    std::deque<int> deque;


    std::cout<<"\n - Push_Back (2 million elements):\n";
    std::cout<<"Vector: ";
    {
        // auto resize 2 - 4 - 8 - 16 - 32
        // therefore, it is not so slow

        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            vector.push_back(i);
        }
    }

    std::cout<<"List: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            list.push_back(i);
        }
    }

    std::cout<<"F_List: ";     //  doesn't have push.back() -> Use insert and some algorithm
    {
        Timer timer;

        f_list.push_front(0);
        auto It = f_list.begin();
        for (int i = 1; i < Number_of_inserts; ++i) {
                It=f_list.insert_after(It,i); // insert_after - returns a iterator to the next element
            }

            // The same

//        auto ItLast_f_list = f_list.before_begin();
//        auto It = f_list.begin();
//        for (int i = 0; i < 2000000; ++i) {
//            for (It; It!= f_list.end();++It) {
//                ItLast_f_list=It;
//            }
//            f_list.insert_after(ItLast_f_list,i);
//            It=ItLast_f_list; // In order not to search from beginning
//       }

    }

    std::cout<<"Deque: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            deque.push_back(i);
        }
    }
}