#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed () : _fixedPointNumValue(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed (){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& 	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		this->_fixedPointNumValue = other.getRawBits();
	}
	return *this;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNumValue);
}
void	Fixed::setRawBits(const int rawbits) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumValue = rawbits;
}