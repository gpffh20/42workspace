#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int fixed_value_;
	static const int fractional_bits_ = 8;
};

#endif
