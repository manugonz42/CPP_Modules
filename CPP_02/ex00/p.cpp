#include <iostream>

class Fixed {
public:
    Fixed() {
        std::cout << "Default constructor called" << std::endl;
    }

    Fixed(const Fixed&) {
        std::cout << "Copy constructor called" << std::endl;
    }

    Fixed& operator=(const Fixed&) {
        std::cout << "Copy assignment operator called" << std::endl;
        getRawBits();
        return *this;
    }

    ~Fixed() {
        std::cout << "Destructor called" << std::endl;
    }

    int getRawBits() const {
        std::cout << "getRawBits member function called" << std::endl;
        return 0;
    }
};

int main() {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
