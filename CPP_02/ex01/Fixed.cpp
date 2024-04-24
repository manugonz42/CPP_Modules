#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed () : _fixedPointNumValue(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed (){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int inum) : _fixedPointNumValue(inum << bitSize){
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float fnum) : _fixedPointNumValue(roundf(fnum * (1 << bitSize))){
	std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed (const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& 	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		this->_fixedPointNumValue = other._fixedPointNumValue;
	}
	return *this;
}

float	Fixed::toFloat() const{
	return (static_cast<float>(this->_fixedPointNumValue) / (1 << bitSize)); //static_cast its like (float) C style conver but more secure, compiler do some checks.
}
int		Fixed::toInt() const{
	return (_fixedPointNumValue >> bitSize);
}

std::ostream& operator<<(std::ostream& o, const Fixed& f){
	o << f.toFloat();
	return o;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNumValue);
}
void	Fixed::setRawBits(const int rawbits) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumValue = rawbits;
}