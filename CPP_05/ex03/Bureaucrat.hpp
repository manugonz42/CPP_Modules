#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;

using std::string;
using std::endl;
using std::cout;
using std::exception;


class Bureaucrat{
    string  name;
    int     grade;
    public:
        Bureaucrat();
        Bureaucrat(const string name, const int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        string  getName() const;
        int     getGrade() const;

        void    incrementGrade();
        void    decrementGrade();

        void    signForm(AForm& form);
        void    executeForm(AForm const & form);

        class   GradeTooHighException: public exception{
            public:
                virtual const char *what() const throw();
        };
        class   GradeTooLowException: public exception{
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& a);

#endif