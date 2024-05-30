#include "Intern.hpp"

Intern::Intern(){
}
Intern::Intern(const Intern& other) {
    *this = other;
}
Intern& Intern::operator=(const Intern& other){
    if (this != &other){
        *this = other;
    }
    return *this;
}
Intern::~Intern(){
}

AForm* Intern::makeForm(const string& name, const string& target){
    string  tlname = name;
    const string  arr[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    int i = 0;
    for (i = 0; i < 3; i++){
        if (tlname == arr[i])
            break;
    }
    AForm*  res = NULL;
    for (std::string::iterator it = tlname.begin(); it != tlname.end(); ++it)
        *it = std::tolower(*it);

    switch (i) {
        case 0:
            res = new RobotomyRequestForm(target);
            break;
        case 1:
            res = new PresidentialPardonForm(target);
            break;
        case 2:
            res = new ShrubberyCreationForm(target);
            break;
        default:
            cout << "Intern cannot find " << name << " form." << endl;
    }
    if (i < 3)
        cout << "Intern creates " << (arr[i] + " form").c_str() << endl;
    return res;
}