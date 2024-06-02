#pragma once
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <stack>
#include <deque>

using std::cout;
using std::endl;

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other){}
        MutantStack& operator=(const MutantStack& other){
            if (this != &other){
                std::stack<T>::operator=(other);
            }
            return *this;
        }
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() { return this->c.begin();}
        iterator end() { return this->c.end();}
};