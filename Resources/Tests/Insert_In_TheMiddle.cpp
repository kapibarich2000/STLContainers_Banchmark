#include <iostream>
#include <Timer.h>
#include <vector>
#include <array> // doesn't have push_back and push_front
#include <list>
#include <forward_list>
#include <deque>

void start_Insert_InTheMiddle(){

    std::vector<int> vector;
//    std::array<int, 500000> array;
    std::list<int> list;
    std::forward_list<int> f_list;
    std::deque<int> deque;

    for (int i = 1; i < 1000000; ++i) {
        vector.push_back(i);
        //array.at(i)=i;
        list.push_back(i);
        f_list.push_front(i);
        deque.push_back(i);
    }
    f_list.reverse();


    std::cout<<" - Insert in the middle 100k elements (when 1 million already filled):\n";

    std::cout<<"Vector: ";
    {
        Timer timer;
        auto it = vector.begin()+((vector.size()/2)-1);
        for (int i = 0; i < 100000; ++i) {
            vector.insert(it,i);
           it = vector.begin()+((vector.size()/2)-1);
        }
        //++it; //Don't work
        // std::advance(it,1); //Don't work
    }

    std::cout<<"List: ";
    {
        Timer timer;
        auto middle = list.begin();
        std::advance(middle,(list.size()/2)-1);
        for (int i = 0; i < 100000; ++i) {
            list.insert(middle,i);
           ++middle;
        }
        // The same result:
        // advance(middle,1);
    }

    std::cout<<"F_List: ";
    // doesn't have size() -> Use search cycle, memory variable and some algorithm
    {
        Timer timer;
        int middle_of_FList = (1000000/2)-1; //Because we count elements from 0
        auto IMiddle_f_list = f_list.before_begin();
        auto It = f_list.begin();
        int i=0;
        while (i!=middle_of_FList){
            ++It;
            ++i;
        }
        IMiddle_f_list = It;

        for (int j = 0; j < 100000; ++j) {
            f_list.insert_after(IMiddle_f_list, j);
            ++IMiddle_f_list; // In order not to search from beginning
        }
    }

    std::cout<<"Deque (10k because it works for a long time): ";
    {
        Timer timer;
        auto middle = deque.begin();
        std::advance(middle,(deque.size()/2)-1);

        for (int i = 0; i < 10000; ++i) {
            deque.insert(middle,i);
            middle = deque.begin()+((deque.size()/2)-1);
        }
    }
}
