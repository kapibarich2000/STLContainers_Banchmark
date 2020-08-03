#include <iostream>
#include <Timer.h>

#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>

#include <set>
#include <map>

#include <unordered_set>
#include <unordered_map>

void start_FindElement_CalculateAmount() {

    std::vector<int> vector;
    std::array<int, 500000> array; // Сan't hold any more
    std::list<int> list;
    std::forward_list<int> f_list;
    std::deque<int> deque;

    std::set<int> set;
    std::multiset<int> multiset;
    std::map<int,int> map;
    std::multimap<int,int> multimap;

    std::unordered_set<int> un_set;
    std::unordered_multiset<int> un_multiset;
    std::unordered_map<int,int> un_map;
    std::unordered_multimap<int,int> un_multimap;

    std::cout<<"Filling containers... \n\n";

    for (int i = 0; i < 500000; ++i) {
        array[i]=i;
    }

    for (int i = 0; i < 2000000; ++i) {
        vector.push_back(i);
        list.push_back(i);
        f_list.push_front(i);
        deque.push_back(i);

        set.emplace(i);
        multiset.emplace(i);
        map.emplace(i,i);
        multimap.emplace(i,i);

        un_set.emplace(i);
        un_multiset.emplace(i);
        un_map.emplace(i,i);
        un_multimap.emplace(i,i);
    }
    f_list.reverse();

    std::cout<<"\n - Find element with value = 1888444, when containers are filled with 2kk:\n";

    std::cout<<"Vector: ";
    {
        Timer timer;
        for (int i = 0; i < vector.size(); ++i) {
            if (vector.at(i)==1888444){
                break;
            }
        }
    }

    std::cout<<"Array (Search 448000, because Array stores max 500k elements): ";
    {
        Timer timer;
        for (int i = 0; i < array.size(); ++i) {
            if (array.at(i)==448000){
                break;
            }
        }
    }

    std::cout<<"List: ";
    {
        Timer timer;
        for (auto it = list.begin(); it!= list.end(); ++it) {
            if (*it==1888444){
                break;
            }
        }
    }
    std::cout<<"F_List: ";
    {
        Timer timer;
        for (auto it = f_list.begin(); it!= f_list.end(); ++it) {
            if (*it==1888444){
                break;
            }
        }
    }
    std::cout<<"Deque: ";
    {
        Timer timer;
        for (auto it = deque.begin(); it!= deque.end(); ++it) {
            if (*it==1888444){
                break;
            }
        }
    }
    std::cout<<"\t __ There are find() method: __ \n "; // for beauty


    std::cout<<"Set: ";
    {
        Timer timer;
        auto it=set.find(1888444);
    }
    std::cout<<"MultiSet: ";
    {
        Timer timer;
        auto it=multiset.find(1888444);
    }
    std::cout<<"Map: ";
    {
        Timer timer;
        auto it=map.find(1888444);
    }
    std::cout<<"MultiMap: ";
    {
        Timer timer;
        auto it=multimap.find(1888444);
    }

    std::cout<<"\n "; // for beauty

    std::cout<<"UnorderedSet: ";
    {
        Timer timer;
        auto it=un_set.find(1888444);
    }
    std::cout<<"UnorderedMultiSet: ";
    {
        Timer timer;
        auto it=un_multiset.find(1888444);
    }
    std::cout<<"UnorderedMap: ";
    {
        Timer timer;
        auto it=un_map.find(1888444);
    }
    std::cout<<"UnorderedMultiMap: ";
    {
        Timer timer;
        auto it=un_multimap.find(1888444);
    }

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";


    std::cout<<"\n - Calculate the sum of element values (2kk elements):\n";

    std::cout<<"Vector: ";
    {
        Timer timer;
        unsigned long long counter;
        for (int i = 0; i < vector.size(); ++i) {
            counter+=vector[i];
        }
    }

    std::cout<<"Array: ";
    {
        Timer timer;
        unsigned long long counter;
        for (int i = 0; i < array.size(); ++i) {
            counter+=array[i];
        }
    }

    std::cout<<"List: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = list.begin(); it!= list.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"F_List: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = f_list.begin(); it!= f_list.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"Deque: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = deque.begin(); it!= deque.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"\t _______ \n "; // for beauty

    std::cout<<"Set: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = set.begin(); it!= set.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"MultiSet: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = multiset.begin(); it!= multiset.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"Map: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = map.begin(); it!= map.end(); ++it) {
            counter+=it->second;
        }
    }

    std::cout<<"MultiMap: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = multimap.begin(); it!= multimap.end(); ++it) {
            counter+=it->second;
        }
    }

    std::cout<<"\t _______ \n "; // for beauty

    std::cout<<"UnorderedSet: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = un_set.begin(); it!= un_set.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"UnorderedMultiSet: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = un_multiset.begin(); it!= un_multiset.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"UnorderedMap: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = un_multimap.begin(); it!= un_multimap.end(); ++it) {
            counter+=it->second;
        }
    }

    std::cout<<"UnorderedMultiMap: ";
    {
        Timer timer;
        unsigned long long counter;
        for (auto it = un_multimap.begin(); it!= un_multimap.end(); ++it) {
            counter+=it->second;
        }
    }

}