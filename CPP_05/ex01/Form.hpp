#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

using std::string;
using std::endl;
using std::cout;
using std::exception;

class Form{
    private:
        const string    name;
        bool            signed_status;
        int       sig_grade;
        int       exe_grade;
    public:
        Form();
        Form(const string name, const int sig_grade, const int exe_grade);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        string  getName() const;
        bool    getSignedStatus() const;
        int     getSigGrade() const;
        int     getExeGrade() const;
        
        void    beSigned(Bureaucrat& a);

        class   GradeTooHighException: public exception{
            public:
                virtual const char *what() const throw();
        };
        class   GradeTooLowException: public exception{
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const Form& a);

#endif