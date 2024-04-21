#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void    Harl::debug(){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void    Harl::info(){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put   enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void    Harl::warning(){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void    Harl::error(){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void    Harl::complain(std::string level){
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    std::size_t i;
    for (i = 0; i < 4; i++){
        if (level == levels[i])
            break ;
    }
    switch (i)
    {
        case 0:
            this->debug();
            /* FALLTHROUGH */
        case 1:
            this->info();
            /* FALLTHROUGH */
        case 2:
            this->warning();
            /* FALLTHROUGH */
        case 3:
            this->error();
            break;

        default:
		    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}