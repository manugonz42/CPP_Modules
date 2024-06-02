#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include <exception>
#include <iterator>

using std::cout;
using std::endl;
using std::string;

class   NotFoundException : public std::exception {
    public:
        const char *what() const throw() {
            return ("Element not found");
        }
};

template <typename T>
typename T::iterator easyfind(T& i, int n){
    typename T::iterator result;
    result = std::find(i.begin(), i.end(), n);
    if (result == i.end())
        throw (NotFoundException());
    return result;
}
