#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include <exception>
#include <iterator>
#include <sstream>
#include <fstream>
#include <map>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

class BitcoinExchange {
    private:
        std::map < unsigned long, unsigned int >    base;
        void    saveBase();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        
};