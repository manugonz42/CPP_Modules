#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class   ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        template <typename T>
        static  T convert(const string &literal);
};