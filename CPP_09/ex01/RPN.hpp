#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include <exception>
#include <iterator>
#include <sstream>
#include <fstream>
#include <stack>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

class RPN {
    private:
        std::stack < float >    base;
        void    saveBase();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

    public:
        RPN();
        ~RPN();
        
};