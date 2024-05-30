#include "Bureaucrat.hpp"
//----------------CONSTRUCTORS-DESTRUCTOR----------------//
Bureaucrat::Bureaucrat() : name("no_name"), grade(150){
    cout << "Base constructor called, grade set to the minimun value." << endl;
}
Bureaucrat::Bureaucrat(const string name, const int grade) : name(name), grade(grade) {
    cout << "With data constructor called, name: " << name << ", grade: " << grade << endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& other){
    cout << "Copy constructor called." << endl;
    if (other.grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (other.grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else {
        this->name = other.getName();
        this->grade = other.getGrade();
    }
}
Bureaucrat::~Bureaucrat(){
}

//----------------OPERATORS----------------//
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    cout << "Assignment operator called." << endl;
    if (this != &other){
        if (other.grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (other.grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else {
            this->name = other.getName();
            this->grade = other.getGrade();
    }
    }
    return *this;
}
std::ostream& operator <<(std::ostream& o, const Bureaucrat &a){
    o << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << endl;
    return o;
}

//----------------GETTERS-SETTERS----------------//
int     Bureaucrat::getGrade() const{
    return this->grade;
}
string  Bureaucrat::getName() const{
    return this->name;
}

//----------------INCREMENT-DECREMENT----------------//
void    Bureaucrat::incrementGrade(){
    cout << "Increment grade member function called" << endl;
    if ((this->grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    if ((this->grade - 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade -= 1;
}
void    Bureaucrat::decrementGrade(){
    cout << "Decrement grade member function called" << endl;
    if ((this->grade + 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    if ((this->grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade += 1;
}

//................EXCEPTIONS....................//
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade assignment to Bureaucrat too hight.");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade assignment to Bureaucrat too low.");
}
