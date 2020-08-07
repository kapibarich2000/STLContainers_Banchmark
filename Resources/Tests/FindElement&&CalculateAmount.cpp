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

#include "algorithm"

#define Number_of_searches 100
#define Number_to_search 1888444
#define Number_inthe_container 2000000

void start_FindElement_CalculateAmount() {

    std::vector<int> vector;

   // std::array<int, 500000> array; // Сan't hold any more -> Stack overflow

    std::array<int, Number_inthe_container> *array = new std::array<int, Number_inthe_container>; // Salvation
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

    for (int i = 0; i < Number_inthe_container; ++i) {
        vector.push_back(i);
        array->at(i)=i;
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

    std::cout<<"\n - Find element with value = 1888444 (hundred times), when containers are filled with 2kk:\n";

    std::cout<<"Vector: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            for (int i = 0; i < vector.size(); ++i) {
                if (vector.at(i)==Number_to_search){
                    break;
                }
            }
        }

    }

    std::cout<<"Array: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            for (int i = 0; i < array->size(); ++i) {
                if (array->at(i)==Number_to_search){
                    break;
                }
            }
        }
    }

    std::cout<<"List: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            for (auto it = list.begin(); it!= list.end(); ++it) {
                if (*it==Number_to_search){
                    break;
                }
            }
        }
    }
    //std::find(list.begin(),list.end(),Number_to_search);  //We can also search this way

    std::cout<<"F_List: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            for (auto it = f_list.begin(); it!= f_list.end(); ++it) {
                if (*it==Number_to_search){
                    break;
                }
            }
        }

    }
    std::cout<<"Deque: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            for (auto it = deque.begin(); it!= deque.end(); ++it) {
                if (*it==Number_to_search){
                    break;
                }
            }
        }

    }
    std::cout<<"\t __ There are find() method: __ \n "; // for beauty


    std::cout<<"Set: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            auto it=set.find(Number_to_search);
        }
    }
    std::cout<<"MultiSet: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            auto it=multiset.find(Number_to_search);

        }
    }
    std::cout<<"Map: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            auto it=map.find(Number_to_search);
        }
    }
    std::cout<<"MultiMap: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            auto it=multimap.find(Number_to_search);
        }
    }

    std::cout<<"\n "; // for beauty

    std::cout<<"UnorderedSet: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            auto it=un_set.find(Number_to_search);
        }
    }
    std::cout<<"UnorderedMultiSet: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            auto it=un_multiset.find(Number_to_search);
        }
    }
    std::cout<<"UnorderedMap: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            auto it=un_map.find(Number_to_search);
        }
    }
    std::cout<<"UnorderedMultiMap: ";
    {
        Timer timer;
        for (int n = 0; n < Number_of_searches; ++n) {
            auto it=un_multimap.find(Number_to_search);
        }
    }

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";


    std::cout<<"\n - Calculate the sum of element values (2kk elements):\n";

    std::cout<<"Vector: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (int i = 0; i < vector.size(); ++i) {
            counter+=vector[i];
        }
    }

    std::cout<<"Array: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (int i = 0; i < array->size(); ++i) {
            counter+=array->at(i);
        }
    }

    std::cout<<"List: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = list.begin(); it!= list.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"F_List: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = f_list.begin(); it!= f_list.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"Deque: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = deque.begin(); it!= deque.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"\t _______ \n "; // for beauty

    std::cout<<"Set: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = set.begin(); it!= set.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"MultiSet: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = multiset.begin(); it!= multiset.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"Map: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = map.begin(); it!= map.end(); ++it) {
            counter+=it->second;
        }
    }

    std::cout<<"MultiMap: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = multimap.begin(); it!= multimap.end(); ++it) {
            counter+=it->second;
        }
    }

    std::cout<<"\t _______ \n "; // for beauty

    std::cout<<"UnorderedSet: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = un_set.begin(); it!= un_set.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"UnorderedMultiSet: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = un_multiset.begin(); it!= un_multiset.end(); ++it) {
            counter+=*it;
        }
    }

    std::cout<<"UnorderedMap: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = un_multimap.begin(); it!= un_multimap.end(); ++it) {
            counter+=it->second;
        }
    }

    std::cout<<"UnorderedMultiMap: ";
    {
        Timer timer;
        unsigned long long counter=0;
        for (auto it = un_multimap.begin(); it!= un_multimap.end(); ++it) {
            counter+=it->second;
        }
    }

}