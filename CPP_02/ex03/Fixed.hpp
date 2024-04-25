#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class	Fixed{
	private:
		int					_fixedPointNumValue;
		static const int	bitSize = 8;
	public:
		Fixed();
		Fixed(const int inum);
		Fixed(const float fnum);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		bool	operator<(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;

		Fixed	operator++(int);	//post
		Fixed&	operator++(void);	//pre
		Fixed	operator--(int);
		Fixed&	operator--(void);

		static Fixed&		min(Fixed& a, Fixed& b);
		const static Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		const static Fixed&	max(const Fixed& a, const Fixed& b);

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(const int rawbits);
};

std::ostream& operator<<(std::ostream& o, const Fixed& f);
#endif