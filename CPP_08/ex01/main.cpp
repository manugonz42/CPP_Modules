#include "Span.hpp"

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const Span::MaxNumbersException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const Span::NotEnoughNumbersException& e) {
        std::cerr << e.what() << std::endl;
    } 

    return 0;
}