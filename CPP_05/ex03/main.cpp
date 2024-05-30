#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main( void )
{
    string a = "presidential pardon", b = "shrubbery creation", c = "robotomy request";
    try {
        AForm *form;
        Intern intern;
        form = intern.makeForm(a, "pepo");
        if (form)
            cout << *form << endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 1;
}