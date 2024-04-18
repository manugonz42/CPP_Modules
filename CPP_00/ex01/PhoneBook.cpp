#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : index(0){
}
PhoneBook::~PhoneBook(void){
}

void    PhoneBook::add_contact(void){
    std::string input;
    std::cout << "Enter the first name:" << std::endl << "> " << std::flush;
    std::cin >> input;
    _contacts[index % 8].add_field("fname", input);
    std::cout << "Enter the last name:" << std::endl << "> " << std::flush;
    std::cin >> input;
    _contacts[index % 8].add_field("lname", input);
    std::cout << "Enter the nickname:" << std::endl << "> " << std::flush;
    std::cin >> input;
    _contacts[index % 8].add_field("nick", input);
    std::cout << "Enter the phone number:" << std::endl << "> " << std::flush;
    std::cin >> input;
    _contacts[index % 8].add_field("phnum", input);
    std::cout << "Enter the darkest secret:" << std::endl << "> " << std::flush;
    std::cin >> input;
    _contacts[index % 8].add_field("secret", input);
}

void    PhoneBook::search(void) const{

    std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
    for (int i = 0; i < 8; i++){
        if (_contacts[i].is_setted())
            _contacts[i].print_contact();
        else
            break;
    }
}

void    PhoneBook::welcome(void) const{
    std::cout << std::endl;
    std::cout << "📞        Welcome to Your Awesome PhoneBook" << std::endl << std::endl;
    std::cout << "Rules:" << std::endl << std::endl;
    std::cout << "You have 3 posible inputs:" << std::endl << std::endl;
    std::cout << "  ADD -> to add a new contact to the PhoneBook." << std::endl;
    std::cout << "  SEARCH -> print the list of the added contacts." << std::endl;
    std::cout << "  EXiT -> to exit of the awesome PhoneBook 📖" << std::endl << std::endl;
    std::cout << "any other input will be ignored" << std::endl;
}