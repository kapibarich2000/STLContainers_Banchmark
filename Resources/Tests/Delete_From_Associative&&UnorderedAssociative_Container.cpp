#include "iostream"
#include <Timer.h>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#define Number_of_deletions 2000000



void start_DeletingFrom_Associative_And_UnorderedAssociative_Containers(){
    std::set<int> set;
    std::multiset<int> multiset;
    std::map<int,int> map;
    std::multimap<int,int> multimap;

    std::unordered_set<int> un_set;
    std::unordered_multiset<int> un_multiset;
    std::unordered_map<int,int> un_map;
    std::unordered_multimap<int,int> un_multimap;

    std::cout<<"Filling containers... \n\n";

    for (int i = 0; i < Number_of_deletions; ++i) {
        set.emplace(i);
        multiset.emplace(i);
        map.emplace(i,i);
        multimap.emplace(i,i);

        un_set.emplace(i);
        un_multiset.emplace(i);
        un_map.emplace(i,i);
        un_multimap.emplace(i,i);
    }

    std::cout<<" - Delete 2 million elements from Associative containers :\n";

    std::cout<<"Set: ";
    {
        Timer timer;
        while (!set.empty())
             set.erase(set.begin());
    }

    std::cout<<"MultiSet: ";
    {
        Timer timer;
        while (!multiset.empty())
            multiset.erase(multiset.begin());
    }


    std::cout<<"Map: ";
    {
        Timer timer;
        while (!map.empty())
            map.erase(map.begin());
    }

    std::cout<<"MultiMap: ";
    {
        Timer timer;
        while (!multimap.empty())
            multimap.erase(multimap.begin());
    }

    std::cout<<"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n"; // For beauty

    std::cout<<" - Delete 2 million elements from Unordered Associative containers :\n";

    std::cout<<"Unordered_Set: ";
    {
        Timer timer;
        while (!un_set.empty())
            un_set.erase(un_set.begin());
    }

    std::cout<<"Unordered_MultiSet: ";
    {
        Timer timer;
        while (!un_multiset.empty())
            un_multiset.erase(un_multiset.begin());
    }

    std::cout<<"Unordered_Map: ";
    {
        Timer timer;
        while (!un_map.empty())
            un_map.erase(un_map.begin());
    }

    std::cout<<"Unordered_MultiMap: ";
    {
        Timer timer;
        while (!un_multimap.empty())
            un_multimap.erase(un_multimap.begin());
    }

}
