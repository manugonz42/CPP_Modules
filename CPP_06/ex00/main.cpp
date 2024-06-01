#include "defines.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include "ScalarConverter.hpp"
#include <iomanip>


void	printthis(char c)
{
	std::cout << "Char: ";
	if (c < 0)
		std::cout << "Impossible";
	else if (c < 32 || c > 126)
		std::cout << " Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

void	printthis(int i)
{
	std::cout << "Int: ";
	if (i == -1)
		std::cout << "Impossible";
    if (i == -2)
        std::cout << "Overflow";
	else
		std::cout << i;
	std::cout << std::endl;
}

void	printthis(float i)
{
	std::cout << "Float: ";
	if (i == -1)
		std::cout << "Impossible";
    if (i == -2)
        std::cout << "Overflow";
	else if (std::isnan(i))
		std::cout << "nanf";
	else
	{
		std::cout << i;
		(i - floor(i)) > 0.0f ? std::cout << "f" : std::cout << ".0f";
	}
	std::cout << std::endl;
}

void	printthis(double i)
{
	std::cout << "Double: ";
	if (i == -1)
		std::cout << "Impossible";
    if (i == -2)
        std::cout << "Overflow";
	else if (std::isnan(i))
		std::cout << "nan";
	else
	{
		std::cout << i;
		if (!((i - floor(i)) > 0.0f))
			std::cout << ".0";
	}
	std::cout << std::endl;
}

int count_ocurrences(char c, char *s){
    int i = -1;
    int count = 0;
    while (s[++i]){
        if (s[i] == c)
            count++;
    }
    return count;
}

int is_int(char *s){
    int i = -1;
    if (s[0] == '+' || s[0] == '-')
        i++;
    while (s[++i]){
        if (!std::isdigit(s[i]))
            return 0;
    }
    return 1;
}

int is_float(char *s){
    int i = -1;
    if (s[0] == '+' || s[0] == '-')
        i++;
    while (s[++i]){
        if (!std::isdigit(s[i]) && s[i] != '.'){
            if (s[i] == 'f' && !s[i + 1])
                continue ;
            return 0;
        }
    }
    if (s[i - 1] == 'f' && (count_ocurrences('.', s) == 1 || count_ocurrences('.', s) == 0))
        return 1;
    return 0;
}

int is_double(char *s){
    int i = -1;
    if (s[0] == '+' || s[0] == '-')
        i++;
    while (s[++i]){
        if (!std::isdigit(s[i]) && s[i] != '.')
            return 0;
    }
    if (count_ocurrences('.', s) == 1)
        return 1;
    return 0;
}

void    print_specials(const char *s){
    cout << "Char:   impossible" <<endl;
    cout << "Int:    impossible" <<endl;
    cout << "Float:  " << s << "f" << endl;
    cout << "Double: " << s << endl; 
}

int parsing(char *str){
    if (!strcmp(str, "nan"))
        print_specials("nan");
    if (!strcmp(str, "+inf") || !strcmp(str, "+inff"))
        print_specials("inf");
    if (!strcmp(str, "-inf") || !strcmp(str, "-inff"))
        print_specials("-inf");
    if ((strlen(str) == 1 && str[0] > 31 && str[0] < 127))
        return _CHAR;
    if (is_int(str))
        return _INT;
    if (is_float(str))
        return _FLOAT;
    if (is_double(str))
        return _DOUBLE;
    return 0;
}

int main(int argc, char **argv)
{
    char    c;
    int     i;
    float   f;
    double  d;

	if (argc != 2 || !argv[1] || strlen(argv[1]) == 0)
		return (printf("Bad parameters. Use ./Converter <VALUE>\n"));
	std::string str(argv[1]);

    int type = parsing(argv[1]);
    //cout << "Type: " << type << endl;
    if (type == 0){
        cout << "Char:   Impossible" << endl;
        cout << "Int:    Impossible" << endl;
        cout << "Float:  Impossible" << endl;
        cout << "Double: Impossible" << endl;
        return 1;
    }
    if (type == _CHAR){
        c = ScalarConverter::convert<char>(str);
        i = static_cast<int>(c);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    if (type == _INT){
        i = ScalarConverter::convert<int>(str);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    if (type == _FLOAT){
        f = ScalarConverter::convert<float>(str);
        if ((f - floor(f)) > 0.0f)
            c = 0;
        else
            c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    }
    if (type == _DOUBLE){
        d = ScalarConverter::convert<double>(str);
        if ((d - floor(d)) > 0.0f)
            c = 0;
        else
            c = static_cast<char>(d);
        f = static_cast<float>(d);
        i = static_cast<int>(d);
    }
    printthis(c);
    printthis(i);
    printthis(f);
    printthis(d);  
}