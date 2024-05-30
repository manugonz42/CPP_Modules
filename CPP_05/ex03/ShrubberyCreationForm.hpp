#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

using std::string;
using std::endl;
using std::cout;
using std::exception;

class ShrubberyCreationForm : public AForm{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        void    execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm& a);

#endif