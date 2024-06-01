#include "ScalarConverter.hpp"
#include <type_traits>
#include <iostream>
#include <math.h>

template <typename T, typename U>
struct IsSame {
    static const bool value = false;
};

template <typename T>
struct IsSame<T, T> {
    static const bool value = true;
};

template char ScalarConverter::convert(const std::string&);
template int ScalarConverter::convert(const std::string&);
template float ScalarConverter::convert(const std::string&);
template double ScalarConverter::convert(const std::string&);

template<typename T>
T ScalarConverter::convert(const std::string &str)
{
	T result;

	if (IsSame<T, char>::value)
	{
        char r;
        r = str[0];
		return (r);
	}
	if (IsSame<T, int>::value)
	{
        try{
            result = std::stoi(str);
        } catch (std::out_of_range& e) {
            result = -2;
        } catch (std::exception& e) {
            result = -1;
        }
		return (result);
	}
	if (IsSame<T, float>::value)
	{
		float r;
		try { 
            r = std::stof(str); 
        } catch (std::out_of_range& e) {
            result = -2;
        } catch (std::exception& e) {
            result = -1;
        }
		return (r);
	}
	if (IsSame<T, double>::value)
	{
		double r;
		try {
            r = std::stod(str); 
        } catch (std::out_of_range& e) {
            result = -2;
        } catch (std::exception& e) {
            result = -1;
        }
		return (r);
	}
	result = -1;
	return result;
}