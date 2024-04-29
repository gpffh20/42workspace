#include "Fixed.hpp"

Fixed::Fixed() {
	this->fixed_value_ = 0;
}

Fixed::Fixed(const int value) {
	this->fixed_value_ = value << this->fractional_bits_;
}

Fixed::Fixed(const float value) {
	this->fixed_value_ = roundf(value * (1 << this->fractional_bits_));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	this->fixed_value_ = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (this->fixed_value_);
}

void Fixed::setRawBits(int const raw) {
	this->fixed_value_ = raw;
}

float Fixed::toFloat(void) const {
	return ((float)this->fixed_value_ / (1 << this->fractional_bits_));
}

int Fixed::toInt(void) const {
	return (this->fixed_value_ >> this->fractional_bits_);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &fixed) const {
	return (this->fixed_value_ > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const {
	return (this->fixed_value_ < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return (this->fixed_value_ >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return (this->fixed_value_ <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const {
	return (this->fixed_value_ == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return (this->fixed_value_ != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed result;

	result.setRawBits(this->fixed_value_ + fixed.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed result;

	result.setRawBits(this->fixed_value_ - fixed.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	Fixed result;

	result.setRawBits((this->fixed_value_ * fixed.getRawBits()) >> this->fractional_bits_);
	return (result);
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	Fixed result;

	result.setRawBits((this->fixed_value_ << this->fractional_bits_) / fixed.getRawBits());
	return (result);
}

Fixed &Fixed::operator++(void) {
	this->fixed_value_++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);

	this->fixed_value_++;
	return (tmp);
}

Fixed &Fixed::operator--(void) {
	this->fixed_value_--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);

	this->fixed_value_--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}