#include <iostream>
#include <string>

class	Fixed{
	private:
		int					_fixedPointNumValue;
		static const int	bitSize = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(const int rawbits);
};