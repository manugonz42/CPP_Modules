#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

using std::string;
using std::endl;
using std::cout;
using std::exception;

class RobotomyRequestForm : public AForm{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        void    execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm& a);

#endif