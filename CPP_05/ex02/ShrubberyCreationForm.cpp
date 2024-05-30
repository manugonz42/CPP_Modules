#include "ShrubberyCreationForm.hpp"

//----------------CONSTRUCTORS-DESTRUCTOR----------------//
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "no_target", 25, 5){
    cout << "--ShrubberyCreationForm Base constructor called--" << endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const string target) : AForm("ShrubberyCreationForm", target, 25, 5) {
    cout << "--ShrubberyCreationForm data constructor called--" << endl << "\t\33[3m" << *this << "\33[0m" <<endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getTarget(), other.getSigGrade(), other.getExeGrade()) {
    cout << "ShrubberyCreationForm Copy constructor called." << endl;
    if (other.getSigGrade() < 1 || other.getExeGrade() < 1){
        delete this;
        throw ShrubberyCreationForm::GradeTooHighException();
    }
    if (other.getSigGrade() > 150 || other.getExeGrade() > 150){
        delete this;
        throw ShrubberyCreationForm::GradeTooLowException();
    }
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
    //cout << "ShrubberyCreationForm destructor called" << endl;
}

//----------------OPERATORS----------------//
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    cout << "ShrubberyCreationForm Assignment operator called." << endl;
    if (this != &other){
            AForm::operator=(other);
    }
    return *this;
}
std::ostream& operator <<(std::ostream& o, const ShrubberyCreationForm &a){
    o << "ShrubberyCreationForm target:" << a.getTarget() << ", signing grade: " << a.getSigGrade() << ", execution grade: " << a.getExeGrade() << endl;
    return o;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getSignedStatus())
        throw ShrubberyCreationForm::NotSignedException();
    if (getExeGrade() < executor.getGrade())
        throw ShrubberyCreationForm::GradeTooLowException();
    std::ofstream file((getTarget() + "_shrubbery").c_str());
    file << "               ,@@@@@@@," << endl;
    file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << endl;
    file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << endl;
    file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << endl;
    file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << endl;
    file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << endl;
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << endl;
    file << "       |o|        | |         | |" << endl;
    file << "       |.|        | |         | |" << endl;
    file << "\\/\\ \\\\/ .\\_//_/__/  ,\\_//__\\\\/.  \\_//__/" << endl;
}
