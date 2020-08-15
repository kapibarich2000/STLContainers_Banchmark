#include <iostream>
#include <Timer.h>

#include <vector>
#include <array> // can't be merged
#include <list>
#include <forward_list>
#include <deque>

#include <set>
#include <map>

#define Number_of_elements_in_containers 500000

void start_Merging_Test() {

    std::vector<int> vector1;
    std::vector<int> vector2;

    std::list<int> list1;
    std::list<int> list2;

    std::forward_list<int> f_list1;
    std::forward_list<int> f_list2;

    std::deque<int> deque1;
    std::deque<int> deque2;


    std::set<int> set1;
    std::set<int> set2;

    std::map<int,int> map1;
    std::map<int,int> map2;

    for (int i = 0; i < Number_of_elements_in_containers; ++i) { // from 0 to 500k
        vector1.push_back(i);
        list1.push_back(i);
        f_list1.push_front(i);
        deque1.push_back(i);

        set1.emplace(i);
        map1.emplace(i,i);
    }
    f_list1.reverse();

    for (int i = Number_of_elements_in_containers, j=0; i < Number_of_elements_in_containers*2; ++i,j++) { // from 500k to 1kk
        vector2.push_back(i);
        list2.push_back(i);
        f_list2.push_front(i);
        deque2.push_back(i);

        set2.emplace(i);
        map2.emplace(i,i);
    }
    f_list2.reverse();


    std::cout<<"Vector: ";
    //добавить vectror2 к vector1, в конец
    {
        Timer timer;
        vector1.insert(vector1.end(), vector2.begin(), vector2.end());
        vector2.clear();
        vector2.shrink_to_fit();
    }

    // This is how we can manually merge arrays

//    std::cout<<"Array: ";
//    {
//        Timer timer;
//        std::array<int,array1.size()+array2.size()> array3;
//        for (int i = 0; i < array1.size(); ++i) {
//            array3[i]=array1[i];
//        }
//        for (int i = 0, j=array3.size()-1; i < array1.size(); ++i,j++) {
//            array3[j]=array2[i];
//        }
//    }


    std::cout<<"List: ";
    {
        Timer timer;
        list1.merge(list2);
        // Longer
        //list1.insert(list1.end(), list2.begin(), list2.end());
        list2.clear();

    }

    std::cout<<"F_List: ";
    {
        Timer timer;
        f_list1.reverse();
        for (auto it = f_list2.begin(); !(f_list2.empty());) {
            f_list1.push_front(*it);
            f_list2.pop_front();
        }
    }

    std::cout<<"Deque: ";
    {
        Timer timer;
        deque1.insert(deque1.end(),deque2.begin(),deque2.end());
        deque2.clear();
    }

    std::cout<<"Set: "; //no other way
    {
        Timer timer;
        for(auto it=set2.begin();it!=set2.end();++it)
            set1.insert(*it);
    }
    std::cout<<"Map: "; //no other way
    {
        Timer timer;
        for(auto it=map2.begin();it!=map2.end();++it)
            map1.insert(*it);
    }
}
