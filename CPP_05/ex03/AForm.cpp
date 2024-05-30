#include "AForm.hpp"

//----------------CONSTRUCTORS-DESTRUCTOR----------------//
AForm::AForm() : name("no_name"), target("no_target"), signed_status(false), sig_grade(150), exe_grade(150){
    cout << "--AForm Base constructor called--" << endl << "\t\33[3mall grades setted to the minimun value\33[0m" << endl;
}
AForm::AForm(const string name, const int sig_grade, const int exe_grade) : name(name), target("no_target"), sig_grade(sig_grade), exe_grade(exe_grade) {
    cout << "--AForm data constructor called--" << endl << "\t\33[3m" << *this << "\33[0m" <<endl;
    if (sig_grade < 1 || exe_grade < 1)
        throw AForm::GradeTooHighException();
    if (sig_grade > 150 || exe_grade > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(const string name, const string target, const int sig_grade, const int exe_grade) : name(name), target(target), sig_grade(sig_grade), exe_grade(exe_grade) {
    cout << "--AForm data constructor called--" << endl << "\t\33[3m" << *this << "\33[0m" <<endl;
    if (sig_grade < 1 || exe_grade < 1)
        throw AForm::GradeTooHighException();
    if (sig_grade > 150 || exe_grade > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm& other) : name(other.getName()){
    cout << "AForm Copy constructor called." << endl;
    if (other.sig_grade < 1 || other.exe_grade < 1)
        throw AForm::GradeTooHighException();
    else if (other.sig_grade > 150 || other.exe_grade > 150)
        throw AForm::GradeTooLowException();
    else {
        this->sig_grade = other.getSigGrade();
        this->exe_grade = other.getExeGrade();
    }   
}
AForm::~AForm(){
    //cout << "AForm destructor called" << endl;
}

//----------------OPERATORS----------------//
AForm& AForm::operator=(const AForm& other){
    cout << "AForm Assignment operator called." << endl;
    if (this != &other){
        if (sig_grade < 1 || exe_grade < 1)
            throw AForm::GradeTooHighException();
        else if (sig_grade > 150 || exe_grade > 150)
            throw AForm::GradeTooLowException();
        else {
            this->sig_grade = other.getSigGrade();
            this->exe_grade = other.getExeGrade();
    }
    }
    return *this;
}
std::ostream& operator <<(std::ostream& o, const AForm &a){
    o << "AForm: " << a.getName() << ", signing grade: " << a.getSigGrade() << ", execution grade: " << a.getExeGrade() << endl;
    return o;
}

//----------------GETTERS-SETTERS----------------//
bool    AForm::getSignedStatus() const{
    return this->signed_status;
}
string  AForm::getName() const{
    return this->name;
}
string  AForm::getTarget() const{
    return this->target;
}
int     AForm::getSigGrade() const {
    return this->sig_grade;
}
int     AForm::getExeGrade() const {
    return this->exe_grade;
}

//------------------EXCEPTIONS------------------------//
const char* AForm::GradeTooHighException::what() const throw() {
    return ("grade too hight.");
}
const char* AForm::GradeTooLowException::what() const throw() {
    return ("grade too low.");
}
const char* AForm::NotSignedException::what() const throw() {
    return ("not signed.");
}

//------------------METHODS--------------------------//
void    AForm::beSigned(Bureaucrat& a){
    if (a.getGrade() > getSigGrade()){
        throw(AForm::GradeTooLowException());
    }
    this->signed_status = true;
}



