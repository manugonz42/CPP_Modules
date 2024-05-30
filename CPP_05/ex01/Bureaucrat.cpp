#include "Bureaucrat.hpp"
#include "Form.hpp"

//----------------CONSTRUCTORS-DESTRUCTOR----------------//
Bureaucrat::Bureaucrat() : name("no_name"), grade(150){
    cout << "--Bureaucrat constructor called-- " << endl << "\t\033[3mGrade set to the minimun value.\033[0m" << endl;
}
Bureaucrat::Bureaucrat(const string name, const int grade) : name(name), grade(grade) {
    //cout << "--Bureaucrat data constructor called-- " << endl << "\t\033[3mName: " << name << ", grade: " << grade << "\033[0m"<< endl;
    cout << "--Bureaucrat data constructor called-- " << endl << "\t\033[3m" << *this << "\033[0m";
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& other){
    cout << "--Bureaucrat copy constructor called--" << endl;
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
    //cout << "Bureaucrat destructor called" << endl;
}

//----------------OPERATORS----------------//
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    cout << "--Bureaucrat assignment operator called--" << endl;
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
    o << "Name: " << a.getName() << ", Bureaucrat grade: " << a.getGrade() << "." << endl;
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

//------------------EXCEPTIONS------------------------//
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade assignment to Bureaucrap too hight.");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade assignment to Bureaucrap too low.");
}


//------------------SIGNFORM--------------------------//

void    Bureaucrat::signForm(Form& form){
    try {
        form.beSigned(*this);
        cout << getName() << " signed " << form.getName() << endl;
    } catch (exception& e) {
        cout << getName() << " couldn´t sign " << form.getName() << " because ";
        cout << e.what() << endl;
    }
}