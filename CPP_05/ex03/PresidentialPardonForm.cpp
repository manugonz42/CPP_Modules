#include "PresidentialPardonForm.hpp"

//----------------CONSTRUCTORS-DESTRUCTOR----------------//
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "no_target", 25, 5){
    cout << "--PresidentialPardonForm Base constructor called--" << endl;
}
PresidentialPardonForm::PresidentialPardonForm(const string target) : AForm("PresidentialPardonForm", target, 25, 5) {
    cout << "--PresidentialPardonForm data constructor called--" << endl << "\t\33[3m" << *this << "\33[0m" <<endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getTarget(), other.getSigGrade(), other.getExeGrade()) {
    cout << "PresidentialPardonForm Copy constructor called." << endl;
    if (other.getSigGrade() < 1 || other.getExeGrade() < 1){
        delete this;
        throw PresidentialPardonForm::GradeTooHighException();
    }
    if (other.getSigGrade() > 150 || other.getExeGrade() > 150){
        delete this;
        throw PresidentialPardonForm::GradeTooLowException();
    }
}
PresidentialPardonForm::~PresidentialPardonForm(){
    //cout << "PresidentialPardonForm destructor called" << endl;
}

//----------------OPERATORS----------------//
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    cout << "PresidentialPardonForm Assignment operator called." << endl;
    if (this != &other){
            AForm::operator=(other);
    }
    return *this;
}
std::ostream& operator <<(std::ostream& o, const PresidentialPardonForm &a){
    o << "PresidentialPardonForm target:" << a.getTarget() << ", signing grade: " << a.getSigGrade() << ", execution grade: " << a.getExeGrade() << endl;
    return o;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getSignedStatus())
        throw PresidentialPardonForm::NotSignedException();
    if (getExeGrade() < executor.getGrade())
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
