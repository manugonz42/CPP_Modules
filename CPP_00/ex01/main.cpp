#include "PhoneBook.hpp"

int main(int argc, char const *argv[]){  
    PhoneBook   book;
    std::string input = "";
    book.welcome();
    while(input.compare("EXIT")){
        if (input.compare("ADD") == 0)
            book.add_contact();
        else if (input.compare("SEARCH") == 0)
            book.search();
        std::cout << "> " << std::flush;
        std::cin >> input;
    }

    return 0;
}