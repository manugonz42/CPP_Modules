#include "whatever.hpp"

template <typename T>
void print(T& element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    // Llama a iter con la función print para cada tipo de array
    std::cout << "Int array: ";
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    std::cout << "Double array: ";
    iter(doubleArray, 5, print<double>);
    std::cout << std::endl;

    std::cout << "Char array: ";
    iter(charArray, 5, print<char>);
    std::cout << std::endl;

    return 0;
}