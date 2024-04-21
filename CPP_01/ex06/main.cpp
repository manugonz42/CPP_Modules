#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl harl;

    if (argc == 1)
        std::cout << "Insert level." << std::endl;
    else
        harl.complain(argv[1]);
    return 0;
}
