#include "PhoneBook.hpp"

int main(void){  
    PhoneBook   book;
    std::string input = "";
    book.welcome();
    while(input.compare("EXIT")){
        if (input.compare("ADD") == 0)
            book.add_contact();
        else if (input.compare("SEARCH") == 0)
            book.search();
        std::cin.clear();
        std::cout << "> " << std::flush;
        std::getline(std::cin, input);
    }
    std::cout << "You have closed succesfully the best PhoneBook of the history." << std::endl;
    return 0;
}