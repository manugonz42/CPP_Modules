#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

using std::string;
using std::endl;
using std::cout;
using std::exception;

class AForm{
    private:
        const string    name;
        const string    target;
        bool            signed_status;
        int       sig_grade;
        int       exe_grade;
    protected:
        AForm();
    public:
        AForm(const string name, const int sig_grade, const int exe_grade);
        AForm(const string name, const string target, const int sig_grade, const int exe_grade);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        string  getName() const;
        string  getTarget() const;
        bool    getSignedStatus() const;
        int     getSigGrade() const;
        int     getExeGrade() const;
        
        void    beSigned(Bureaucrat& a);

        void virtual execute(Bureaucrat const & executor) const = 0;

        class   GradeTooHighException: public exception{
            public:
                virtual const char *what() const throw();
        };
        class   GradeTooLowException: public exception{
            public:
                virtual const char *what() const throw();
        };
        class   NotSignedException: public exception{
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const AForm& a);

#endif