#include <iostream>
#include <Timer.h>
#include <vector>
#include <array> // doesn't have push_back, push_front and insert
#include <list>
#include <forward_list>
#include <deque>

#define Number_of_inserts 100000
#define Number_of_inserts_for_deque 10000
#define Number_inthe_container 1000000

void start_Insert_InTheMiddle(){

    std::vector<int> vector;
    std::list<int> list;
    std::forward_list<int> f_list;
    std::deque<int> deque;

    for (int i = 1; i < Number_inthe_container; ++i) {
        vector.push_back(i);
        list.push_back(i);
        f_list.push_front(i);
        deque.push_back(i);
    }
    f_list.reverse();


    std::cout<<" - Insert in the middle 100k elements (when 1 million already filled):\n";


    std::cout<<"Vector: ";
    auto it = vector.begin()+((vector.size()/2)-1);
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            vector.insert(it,i);
           it = vector.begin()+((vector.size()/2)-1);
        }
        //++it; //Don't work
        // std::advance(it,1); //Don't work
    }


    std::cout<<"List: ";
    auto middle = list.begin();
    std::advance(middle,(list.size()/2)-1);
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            middle= list.insert(middle,i);
           //++middle;  insert() - make this work
        }
        // The same result:
        // advance(middle,1);
    }


    std::cout<<"F_List: ";
    // doesn't have size() -> Use search cycle, memory variable and some algorithm
    // Search for the middle:
    int middle_of_FList = (Number_of_inserts/2)-1; //Because we count elements from 0
    auto IMiddle_f_list = f_list.before_begin();
    auto It = f_list.begin();
    int i=0;
    while (i!=middle_of_FList){
        ++It;
        ++i;
    }
    IMiddle_f_list = It;
    {
        Timer timer;
        for (int j = 0; j < Number_of_inserts; ++j) {
            IMiddle_f_list=f_list.insert_after(IMiddle_f_list, j);
        }
    }


    std::cout<<"Deque (10k because it works for a long time) : ";
    auto middleDeq = deque.begin();
    std::advance(middleDeq,(deque.size()/2)-1);
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts_for_deque; ++i) {
            middleDeq= deque.insert(middleDeq,i);
        }
    }
}
