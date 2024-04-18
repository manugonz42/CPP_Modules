#include "Contact.hpp"

Contact::Contact(/* args */){
}
Contact::~Contact(){
}

void    Contact::add_field(std::string field, std::string content){
    std::string filtered;
    if (content == "EXIT")
        exit(EXIT_SUCCESS);
    else{
        if (content.length() == 10)
            filtered = content;
        else if (content.length() > 10)
            filtered = content.substr(0, 9) + '.';
        else{
            filtered.assign(10 - content.length(), ' ');
            filtered.append(content);
        }
    }
    if (field == "fname")
        add_fname(filtered);
    else if (field == "lname")
        add_lname(filtered);
    else if (field == "phnum")
        add_phnum(filtered);
    else if (field == "nick")
        add_nick(filtered);
    else if (field == "secret")
        add_secret(filtered);
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
bool    Contact::is_setted(void) const{
    return setted;
}

void    Contact::print_contact(void) const{
    std::cout << "|" << _index << "|" << _first_name << "|" << _last_name << "|" << _nickname << std::endl;
}