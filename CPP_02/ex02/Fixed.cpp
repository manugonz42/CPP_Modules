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

//OP COMPARATION

bool	Fixed::operator<(const Fixed& other) const{
	return (this->_fixedPointNumValue < other._fixedPointNumValue) ? true : false;
}
bool	Fixed::operator<=(const Fixed& other) const{
	return (this->_fixedPointNumValue <= other._fixedPointNumValue) ? true : false;
}
bool	Fixed::operator>(const Fixed& other) const{
	return (this->_fixedPointNumValue > other._fixedPointNumValue) ? true : false;
}
bool	Fixed::operator>=(const Fixed& other) const{
	return (this->_fixedPointNumValue >= other._fixedPointNumValue) ? true : false;
}
bool	Fixed::operator==(const Fixed& other) const{
	return (this->_fixedPointNumValue == other._fixedPointNumValue) ? true : false;
}
bool	Fixed::operator!=(const Fixed& other) const{
	return (this->_fixedPointNumValue != other._fixedPointNumValue) ? true : false;
}

//OP ARITHMETIC

Fixed	Fixed::operator+(const Fixed& other) const{
	Fixed	tmp(this->toFloat() + other.toFloat());
	return tmp;
}
Fixed	Fixed::operator-(const Fixed& other) const{
	Fixed	tmp(this->toFloat() - other.toFloat());
	return tmp;
}
Fixed	Fixed::operator*(const Fixed& other) const{
	Fixed	tmp(this->toFloat() * other.toFloat());
	return tmp;
}
Fixed	Fixed::operator/(const Fixed& other) const{
	Fixed	tmp(this->toFloat() / other.toFloat());
	return tmp;
}

//OP INCREMENT/DECREMENT

Fixed	Fixed::operator++(int){
	Fixed	tmp(*this);
	this->_fixedPointNumValue++;
	return tmp;
}
Fixed	Fixed::operator--(int){
	Fixed	tmp(*this);
	this->_fixedPointNumValue--;
	return tmp;
}
Fixed&	Fixed::operator++(void){
	this->setRawBits(this->getRawBits() + 1);
	return(*this);
}
Fixed&	Fixed::operator--(void){
	this->setRawBits(this->getRawBits() - 1);
	return(*this);
}

//MIN MAX FUNCTIONS

Fixed&	Fixed::min(Fixed& a, Fixed& b){
	return (a < b ? a : b);
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b){
	return (a < b ? a : b);
}
Fixed&	Fixed::max(Fixed& a, Fixed& b){
	return (a > b ? a : b);
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b){
	return (a > b ? a : b);
}