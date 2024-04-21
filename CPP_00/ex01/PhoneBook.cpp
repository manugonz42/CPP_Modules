#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : index(0){
}
PhoneBook::~PhoneBook(void){
}
void    PhoneBook::exit_f(void) const{
    std::cout << "You have closed succesfully the best PhoneBook of the history." << std::endl;
    exit (0);
}
std::string PhoneBook::read_input(void) const{
    std::string input;
    std::getline(std::cin, input);
    while(!std::cin.good() || input.empty()){
        std::cin.clear();
        std::cout << "Error reading, try again." << std::endl << "> " << std::flush;
        std::getline(std::cin, input);
    }
    if (input == "EXIT")
        exit_f();
    return input;
}

int PhoneBook::stringToInt(const std::string& str) const{
    int result = 0;
    int sign = 1;
    size_t i = 0;

    while (i < str.length() && isspace(str[i])) {
        ++i;
    }
    if (i < str.length() && (str[i] == '+' || str[i] == '-')) {
        sign = (str[i++] == '-') ? -1 : 1;
    }
    while (i < str.length() && isdigit(str[i])) {
        result = result * 10 + (str[i++] - '0');
    }
    return result * sign;
}

void    PhoneBook::prompt(void) const{
    std::cout << "Enter new command (ADD / SEARCH / EXIT)" << std::endl;
}

void    PhoneBook::add_contact(void){
    std::string input;
    Contact buff;
    buff.add_index(index % 8);
    std::cout << "Enter the first name:" << std::endl << "> " << std::flush;
    input = read_input();
    buff.add_field("fname", input);
    std::cout << "Enter the last name:" << std::endl << "> " << std::flush;
    input = read_input();
    buff.add_field("lname", input);
    std::cout << "Enter the nickname:" << std::endl << "> " << std::flush;
    input = read_input();
    buff.add_field("nick", input);
    std::cout << "Enter the phone number:" << std::endl << "> " << std::flush;
    input = read_input();
    buff.add_field("phnum", input);
    std::cout << "Enter the darkest secret:" << std::endl << "> " << std::flush;
    input = read_input();
    buff.add_field("secret", input);
    buff.setted(true);
    _contacts[index % 8] = buff;
    index++;
    prompt();
}

int    PhoneBook::is_valid_index(const std::string& input) const{
    int in;
    if (input == "EXIT")
        exit_f();
    if (input.length() != 1 || !std::isdigit(input[0]))
        return 0;
    in = stringToInt(input);
    if(in < 0 || in > 9)
        return 0;
    if (_contacts[in].is_setted() == false)
        return 0;
    return 1;
}
void    PhoneBook::search(void) const{

    std::string input;
    int         in;
    if (!_contacts[0].is_setted()){
        std::cout << "No contacts added yet." << std::endl;
        prompt();
        return ;
    }
    std::cout << "------------- PHONEBOOK CONTACTS -------------" << std::endl;
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    for (int i = 0; i < 8; i++){
        if (_contacts[i].is_setted())
            _contacts[i].print_search_contact();
        else
            break;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Enter the index of the contact you want to view." << std::endl << "> " << std::flush;
    input = read_input();
    while(!is_valid_index(input)){
        std::cout << "Enter a valid index." << std::endl << "> " << std::flush;
        input = read_input();
    }
    in = stringToInt(input);
    _contacts[in].print_contact();
    prompt();
}

void    PhoneBook::welcome(void) const{
    std::cout << std::endl;
    std::cout << "📞        Welcome to Your Awesome PhoneBook" << std::endl << std::endl;
    std::cout << "Rules:" << std::endl << std::endl;
    std::cout << "You have 3 posible inputs:" << std::endl << std::endl;
    std::cout << "  ADD    -> to add a new contact to the PhoneBook." << std::endl;
    std::cout << "  SEARCH -> search and print the list of the added contacts." << std::endl;
    std::cout << "  EXIT   -> to exit the awesome PhoneBook 📖" << std::endl << std::endl;
    std::cout << "any other input will be ignored" << std::endl;
}