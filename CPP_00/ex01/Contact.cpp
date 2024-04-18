#include "Contact.hpp"

Contact::Contact(void) : _setted(false){
}
Contact::~Contact(void){
}

void    Contact::add_field(std::string field, std::string content){
    if (content == "EXIT")
        exit(EXIT_SUCCESS);
    while(content.length() <= 0){
        std::cout << "Fields in the Phonebook cannot be empty." << std::endl << "> " << std::flush;
        std::cin >> content;
    }
    if (field == "fname")
        add_fname(content);
    else if (field == "lname")
        add_lname(content);
    else if (field == "phnum")
        add_phnum(content);
    else if (field == "nick")
        add_nick(content);
    else if (field == "secret")
        add_secret(content);
}

void    Contact::add_fname(std::string fname){
    _first_name = fname;
}
void    Contact::add_lname(std::string lname){
    _last_name = lname;
}
void    Contact::add_phnum(std::string number){
    _phone_number = number;
}
void    Contact::add_nick(std::string nick){
    _nickname = nick;
}
void    Contact::add_secret(std::string secret){
    _darkest_secret = secret;
}
void    Contact::setted(bool set){
    _setted = set;
}
bool    Contact::is_setted(void) const{
    return _setted;
}
std::string Contact::filter(std::string content) const{
    std::string filtered;
    if (content.length() == 10)
        filtered = content;
    else if (content.length() > 10)
        filtered = content.substr(0, 9) + '.';
    else{
        filtered.assign(10 - content.length(), ' ');
        filtered.append(content);
    }
    return (filtered);
}

void    Contact::print_search_contact(void) const{
    std::cout << "|" << filter(_index) << "|" << filter(_first_name) << "|" << filter(_last_name) << "|" << filter(_nickname) << std::endl;
}