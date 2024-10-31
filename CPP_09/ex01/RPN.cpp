#include "RPN.hpp"

RPN::RPN() {
};
RPN::RPN(const RPN& other) : base(other.base){
}
RPN& RPN::operator=(const RPN& other){
	if (this != &other){
		this->base = other.base;
	}
	return *this;
}
RPN::~RPN(){
}
