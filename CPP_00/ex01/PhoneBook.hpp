#include "Contact.hpp"

class PhoneBook{
    private:
        Contact _contacts[8];
        int     index;
    public:
        PhoneBook();
        ~PhoneBook();
        void    welcome(void) const;
        void    add_contact(void);
        int     is_valid_index(const std::string& input) const;
        void    search(void) const;
        void    prompt(void) const;
        void    exit_f(void) const;
        int     stringToInt(const std::string& str) const;
        std::string read_input(void) const;
};