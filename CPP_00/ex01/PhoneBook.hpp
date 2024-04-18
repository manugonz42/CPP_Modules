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
        int     is_valid_index(std::string input);
        void    search(void) const;
};