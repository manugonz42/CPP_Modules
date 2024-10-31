#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : base(other.base){
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	if (this != &other){
		this->base = other.base;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange(){
}