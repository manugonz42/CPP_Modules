#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string.h>

class Contact
{
private:
    std::string         _index;
    std::string         _first_name;
    std::string         _last_name;
    std::string         _nickname;
    std::string         _phone_number;
    std::string         _darkest_secret;
    bool                setted;
public:
    Contact(/* args */);
    ~Contact();
    void    add_field(std::string field, std::string content);
    void    add_fname(std::string fname);
    void    add_lname(std::string lname);
    void    add_phnum(std::string number);
    void    add_nick(std::string nick);
    void    add_secret(std::string secret);
    void    print_contact(void) const;
    bool    is_setted(void) const;
};

#endif
