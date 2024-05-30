#include "Bureaucrat.hpp"

int main( void )
{
    Bureaucrat bureaucrat("Perro Sánchez", 1);
    try {
        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        //bureaucrat.decrementGrade();
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << bureaucrat << std::endl;
    return 0;
}