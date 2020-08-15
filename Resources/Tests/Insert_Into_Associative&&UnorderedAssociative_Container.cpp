#include "iostream"
#include <Timer.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#define Number_of_inserts 2000000

void start_InsertInto_Associative_And_UnorderedAssociative_Containers(){
    std::set<int> set;
    std::multiset<int> multiset;
    std::map<int,int> map;
    std::multimap<int,int> multimap;

    std::unordered_set<int> un_set;
    std::unordered_multiset<int> un_multiset;
    std::unordered_map<int,int> un_map;
    std::unordered_multimap<int,int> un_multimap;


    std::cout<<" - Insert 2 million elements in Associative containers :\n";

    std::cout<<"Set: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            set.emplace(i);
        }
    }

    std::cout<<"MultiSet: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            multiset.emplace(i);
        }
    }


    std::cout<<"Map: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            map.emplace(i,i);
        }
    }

    std::cout<<"MultiMap: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            multimap.emplace(i,i);
        }
    }

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n"; // For beauty

    std::cout<<" - Insert 2 million elements in Unordered Associative containers :\n";

    std::cout<<"Unordered_Set: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            un_set.emplace(i);
        }
    }

    std::cout<<"Unordered_MultiSet: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            un_multiset.emplace(i);
        }
    }

    std::cout<<"Unordered_Map: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            un_map.emplace(i,i);
        }
    }

    std::cout<<"Unordered_MultiMap: ";
    {
        Timer timer;
        for (int i = 0; i < Number_of_inserts; ++i) {
            un_multimap.emplace(i,i);
        }
    }

}
