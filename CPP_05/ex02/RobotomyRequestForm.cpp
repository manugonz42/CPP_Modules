#include "RobotomyRequestForm.hpp"

//----------------CONSTRUCTORS-DESTRUCTOR----------------//
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "no_target", 25, 5){
    cout << "--RobotomyRequestForm Base constructor called--" << endl;
}
RobotomyRequestForm::RobotomyRequestForm(const string target) : AForm("RobotomyRequestForm", target, 25, 5) {
    cout << "--RobotomyRequestForm data constructor called--" << endl << "\t\33[3m" << *this << "\33[0m" <<endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getTarget(), other.getSigGrade(), other.getExeGrade()) {
    cout << "RobotomyRequestForm Copy constructor called." << endl;
    if (other.getSigGrade() < 1 || other.getExeGrade() < 1){
        delete this;
        throw RobotomyRequestForm::GradeTooHighException();
    }
    if (other.getSigGrade() > 150 || other.getExeGrade() > 150){
        delete this;
        throw RobotomyRequestForm::GradeTooLowException();
    }
}
RobotomyRequestForm::~RobotomyRequestForm(){
    //cout << "RobotomyRequestForm destructor called" << endl;
}

//----------------OPERATORS----------------//
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    cout << "RobotomyRequestForm Assignment operator called." << endl;
    if (this != &other){
            AForm::operator=(other);
    }
    return *this;
}
std::ostream& operator <<(std::ostream& o, const RobotomyRequestForm &a){
    o << "RobotomyRequestForm target:" << a.getTarget() << ", signing grade: " << a.getSigGrade() << ", execution grade: " << a.getExeGrade() << endl;
    return o;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getSignedStatus())
        throw RobotomyRequestForm::NotSignedException();
    if (getExeGrade() < executor.getGrade())
        throw RobotomyRequestForm::GradeTooLowException();
    static int i = 0;
    if (i % 2 == 0)
        cout << "BZzZzZzZzZzzZZZT! " << getTarget() << " has been robotomized! 🛠️" << endl;
    else
        cout << "Robotomized failed 🤖" << endl;
}
