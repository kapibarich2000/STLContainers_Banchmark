#include <iostream>
#include <Timer.h>

#include <vector>
#include <list>
#include <forward_list>
#include <deque>

#define Number_of_deletions 30000


void start_Delete_FromTheMiddle(){

        std::vector<int> vector;
        std::list<int> list;
        std::forward_list<int> f_list;
        std::deque<int> deque;

    for (int i = 0; i < Number_of_deletions; ++i) { // default 30k
        vector.push_back(i);
        list.push_back(i);
        f_list.push_front(i);
        deque.push_back(i);

    }
    f_list.reverse();

    // we are forced to search the middle of each containers,
    // because method erase return iterator to the next element after erased.
    // And this way we will erase only one half of containers


        std::cout<<" - Delete from the middle 30k elements:\n";

        std::cout<<"Vector: ";
        {
            Timer timer;
            auto middle = vector.begin()+((vector.size()/2));
           while (!vector.empty()){
                vector.erase(middle);
               middle = vector.begin()+((vector.size()/2));
            }
            //++it; //Don't work
            // std::advance(it,1); //Don't work
        }

        std::cout<<"List: ";
        {
            Timer timer;
            auto middle = list.begin();
            std::advance(middle,(list.size()/2));
            while(!list.empty()){
                list.erase(middle);
                middle = list.begin();
                std::advance(middle,(list.size()/2));
            }
        }

        std::cout<<"F_List: ";
        // doesn't have size() -> Use search cycle, memory variable and some algorithm
        {
            Timer timer;
            int size = 30000;
            int middle_of_FList;
            while (!f_list.empty()){
                middle_of_FList = (size/2); //Because we count elements from 0
                auto IMiddle_f_list = f_list.before_begin();
                auto It = f_list.before_begin();
                int i=0;
                while (i!=middle_of_FList){
                    ++It;
                    ++i;
                }
                IMiddle_f_list = It;
            f_list.erase_after(IMiddle_f_list);
            --size;
            }

        }

        std::cout<<"Deque: ";
        {
            Timer timer;
            auto middle = deque.begin();
            std::advance(middle,(deque.size()/2)-1);
            while (!deque.empty()){
                deque.erase(middle);
                middle = deque.begin()+((deque.size()/2)-1);
            }

        }
    }