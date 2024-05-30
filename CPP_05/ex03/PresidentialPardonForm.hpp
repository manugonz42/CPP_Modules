#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

using std::string;
using std::endl;
using std::cout;
using std::exception;

class PresidentialPardonForm : public AForm{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        void    execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm& a);

#endif