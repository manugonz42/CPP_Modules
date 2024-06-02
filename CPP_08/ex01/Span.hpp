#pragma once
#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using std::cout;
using std::endl;

class Span{
    private:
        unsigned int        N;
        std::multiset<int>  container;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        virtual ~Span();
        class   MaxNumbersException : std::exception{
            public:
                const char* what() const throw();
        };
        class   NotEnoughNumbersException : std::exception{
            public:
                const char* what() const throw();
        };
        void    addNumber(unsigned int n);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        const std::multiset<int>  &getContainer() const {
            return container;
        }
};