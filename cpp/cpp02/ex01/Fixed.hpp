#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed {
public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
private:
	int fixed_value_;
	static const int fractional_bits_ = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
