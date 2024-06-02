#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <string>
#include <iostream>

using std::endl;
using std::cout;

template <typename T>
class   Array{
    private:
        unsigned int    len;
        T*              array;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        Array& operator=(const Array& other);
        virtual ~Array();
        unsigned int size() const;

        class InvalidIndexException : public std::exception {
            public: 
                virtual const char* what() const throw();
        };
        T& operator[](unsigned int i);
        T const& operator[](unsigned int i) const;
};
template <typename T>
const char* Array<T>::InvalidIndexException::what()const throw(){
    return "Error: invalid index";
}
#include "Array.tpp"
#endif