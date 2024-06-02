#include "Span.hpp"

Span::Span() : N(0){}
Span::Span(unsigned int N) : N(N) {
}
Span::Span(const Span& other) : N(other.N) {
    container.clear();
    container = other.container;
}
Span::~Span(){
    container.clear();
}
Span& Span::operator=(const Span& other) {
    if (this != &other){
        N = other.N;
        this->container.clear();
        this->container = other.container;
    }
    return *this;
}

void    Span::addNumber(unsigned int n){
    if (container.size() == N)
        throw (MaxNumbersException());
    container.insert(n);
}
unsigned int   Span::shortestSpan() const{
    if (container.size() < 2)
        throw (NotEnoughNumbersException());
    std::multiset<int>::iterator it = container.begin();
    std::multiset<int>::iterator prev = it;
    it++;
    long unsigned int minor = std::abs(*it - *prev);
    long unsigned int buff;
    for (; it != container.end(); it++, prev++){
        buff = std::abs(*it - *prev);
        if (buff < minor)
            minor = buff;
    }
    return (minor);
}

unsigned int   Span::longestSpan() const{
    if (container.size() < 2)
        throw (NotEnoughNumbersException());
    int biggest = *std::max_element(container.begin(), container.end());
	int smallest = *std::min_element(container.begin(), container.end());
    return (std::abs(biggest - smallest));
}

const char* Span::MaxNumbersException::what() const throw(){
    return ("No more space");
}
const char* Span::NotEnoughNumbersException::what() const throw(){
    return ("Not enough numbers");
}