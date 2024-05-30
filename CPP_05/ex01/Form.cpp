#include "Form.hpp"

//----------------CONSTRUCTORS-DESTRUCTOR----------------//
Form::Form() : name("no_name"), signed_status(false), sig_grade(150), exe_grade(150){
    cout << "--Form Base constructor called--" << endl << "\t\33[3mall grades setted to the minimun value\33[0m" << endl;
}
Form::Form(const string name, const int sig_grade, const int exe_grade) : name(name), sig_grade(sig_grade), exe_grade(exe_grade) {
    cout << "--Form data constructor called--" << endl << "\t\33[3m" << *this << "\33[0m" <<endl;
    if (sig_grade < 1 || exe_grade < 1)
        throw Form::GradeTooHighException();
    if (sig_grade > 150 || exe_grade > 150)
        throw Form::GradeTooLowException();
}
Form::Form(const Form& other) : name(other.getName()){
    cout << "Form Copy constructor called." << endl;
    if (other.sig_grade < 1 || other.exe_grade < 1)
        throw Form::GradeTooHighException();
    else if (other.sig_grade > 150 || other.exe_grade > 150)
        throw Form::GradeTooLowException();
    else {
        this->sig_grade = other.getSigGrade();
        this->exe_grade = other.getExeGrade();
    }
}
Form::~Form(){
    //cout << "Form destructor called" << endl;
}

//----------------OPERATORS----------------//
Form& Form::operator=(const Form& other){
    cout << "Form Assignment operator called." << endl;
    if (this != &other){
        if (sig_grade < 1 || exe_grade < 1)
            throw Form::GradeTooHighException();
        else if (sig_grade > 150 || exe_grade > 150)
            throw Form::GradeTooLowException();
        else {
            this->sig_grade = other.getSigGrade();
            this->exe_grade = other.getExeGrade();
    }
    }
    return *this;
}
std::ostream& operator <<(std::ostream& o, const Form &a){
    o << "Form: " << a.getName() << ", signing grade: " << a.getSigGrade() << ", execution grade: " << a.getExeGrade() << endl;
    return o;
}

//----------------GETTERS-SETTERS----------------//
bool    Form::getSignedStatus() const{
    return this->signed_status;
}
string  Form::getName() const{
    return this->name;
}
int     Form::getSigGrade() const {
    return this->sig_grade;
}
int     Form::getExeGrade() const {
    return this->exe_grade;
}

//------------------EXCEPTIONS------------------------//
const char* Form::GradeTooHighException::what() const throw() {
    return ("grade too hight.");
}
const char* Form::GradeTooLowException::what() const throw() {
    return ("grade too low.");
}

//------------------METHODS--------------------------//
void    Form::beSigned(Bureaucrat& a){
    if (a.getGrade() > getSigGrade()){
        throw(Form::GradeTooLowException());
    }
    this->signed_status = true;
}



