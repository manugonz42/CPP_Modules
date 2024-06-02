#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include "easyfind.hpp"
#include <map>

int main(void)
{
    try {
		std::multiset<int> multiset;
		for (int i = 0; i < 5; i++)
			multiset.insert(42 + i);
		std::multiset<int>::iterator found = easyfind(multiset, 42);
		if (found == multiset.end())
			std::cout << "cannot find 42 in multiset" << std::endl;
		else
			std::cout << "found 42 in multiset " << *found << std::endl;
        cout << "trying to find 99" << endl;
		if (easyfind(multiset, 99) == multiset.end())
			std::cout << "99 not found in multiset" << std::endl;
        } catch (const NotFoundException& e){
            cout <<e.what() << endl;
        }
        cout << endl;
	{
        try {
		std::vector<int> vec(5, 5);
		for (int i = 0; i < 5; i++)
			vec[i] = i;
		std::vector<int>::iterator found = easyfind(vec, 2);
		if (found == vec.end())
			std::cout << "cannot find 2 in vector" << std::endl;
		else
			std::cout << "found 2 in vector " << *found << std::endl;
        cout << "trying to find 99" << endl;
		if (easyfind(vec, 99) == vec.end())
			std::cout << "99 not found in vector" << std::endl;
        } catch (const NotFoundException& e){
            cout << e.what() << endl;
        }
	}
    cout << endl;
	{
		try {
		std::deque<int> deque;
		for (int i = 0; i < 5; i++)
			deque.push_back(i);
		std::deque<int>::iterator found = easyfind(deque, 3);
		if (found == deque.end())
			std::cout << "cannot find 3 in deque" << std::endl;
		else
			std::cout << "found 3 in deque " << *found << std::endl;
        cout << "trying to find 99" << endl;
		if (easyfind(deque, 99) == deque.end())
			std::cout << "99 not found in deque" << std::endl;
        } catch (const NotFoundException& e){
            cout << e.what() << endl;
        }
	}
    cout << endl;
        try {
		std::list<int> lst;
		for (int i = 0; i < 5; i++)
			lst.push_back(i + 42);
		std::list<int>::iterator found = easyfind(lst, 42);
		if (found == lst.end())
			std::cout << "cannot find 42 in list" << std::endl;
		else
			std::cout << "found 42 in list " << *found << std::endl;
        cout << "trying to find 99" << endl;
		if (easyfind(lst, 99) == lst.end())
			std::cout << "99 not found in list" << std::endl;
        } catch (const NotFoundException& e){
            cout << e.what() << endl;
        }
	{
        cout << endl;
        try {
		std::set<int> set;
		for (int i = 0; i < 5; i++)
			if (!set.insert(42 + i).second)
				std::cout << "failed to insert " << 42 + i << " in set !" << std::endl;
		std::set<int>::iterator found = easyfind(set, 42);
		if (found == set.end())
			std::cout << "cannot find 42 in set" << std::endl;
		else
			std::cout << "found 42 in set " << *found << std::endl;
        cout << "trying to find 99" << endl;
		if (easyfind(set, 99) == set.end())
			std::cout << "99 not found in set" << std::endl;
        } catch (const NotFoundException& e){
            cout << e.what() << endl;
        }
		
	}
    cout << endl;
        try {
		std::multiset<int> multiset;
		for (int i = 0; i < 5; i++)
			multiset.insert(42 + i);
		std::multiset<int>::iterator found = easyfind(multiset, 42);
		if (found == multiset.end())
			std::cout << "cannot find 42 in multiset" << std::endl;
		else
			std::cout << "found 42 in multiset " << *found << std::endl;
        cout << "trying to find 99" << endl;
		if (easyfind(multiset, 99) == multiset.end())
			std::cout << "99 not found in multiset" << std::endl;
        } catch (const NotFoundException& e){
            cout << e.what() << endl;
        }
	
	return (0);
}