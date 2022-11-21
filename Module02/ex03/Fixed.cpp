/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:06:10 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/21 16:36:29 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor
Fixed::Fixed(): _value(0)
{
}

// int constructor
Fixed::Fixed(const int value)
{
	_value = value * (1 << _numberFractionalBits);
}

// float constructor
Fixed::Fixed(const float value)
{
	_value = std::roundf(value * (1 << _numberFractionalBits));
}

// copy constructor
Fixed::Fixed(const Fixed &fixed)
{
	this->_value = fixed.getRawBits();
}

//copy assignment operator overload
const	Fixed& Fixed::operator=(const Fixed &fixed)
{
	if (this == &fixed)
		return *this;
	this->_value = fixed.getRawBits();
	return *this;
}

// destructor
Fixed::~Fixed()
{
}

// returns the raw value of the fixed-point value
int		Fixed::getRawBits( void ) const { return _value; }

//sets the raw value of the fixed-point number
void	Fixed::setRawBits( int const raw ) { _value = raw; }

// converts the fixed-point value to a floating-point value
float	Fixed::toFloat( void ) const
{
	return (float)_value / float(1 << _numberFractionalBits);
}

// converts the fixed-point value to an integer value
int		Fixed::toInt( void ) const
{
	return _value / (1 << _numberFractionalBits);
}

// comparison operators

bool	Fixed::operator > (const Fixed &value) const { return this->getRawBits() > value.getRawBits(); }
bool	Fixed::operator < (const Fixed &value) const { return this->getRawBits() < value.getRawBits(); }
bool	Fixed::operator >= (const Fixed &value) const { return this->getRawBits() >= value.getRawBits(); }
bool	Fixed::operator <= (const Fixed &value) const { return this->getRawBits() <= value.getRawBits(); }
bool	Fixed::operator == (const Fixed &value) const { return this->getRawBits() == value.getRawBits(); }
bool	Fixed::operator != (const Fixed &value) const { return this->getRawBits() != value.getRawBits(); }

// arithmetic operators
Fixed	Fixed::operator + (const Fixed &value) const { return Fixed(this->toFloat() + value.toFloat()); }
Fixed	Fixed::operator - (const Fixed &value) const { return Fixed(this->toFloat() - value.toFloat()); }
Fixed	Fixed::operator * (const Fixed &value) const { return Fixed(this->toFloat() * value.toFloat()); }
Fixed	Fixed::operator / (const Fixed &value) const { return Fixed(this->toFloat() / value.toFloat()); }

// increment/decrement operators

Fixed	Fixed::operator ++ ()
{
	_value++;
	return *this;
}

Fixed	Fixed::operator -- ()
{
	_value--;
	return *this;
}

Fixed	Fixed::operator ++ (int n)
{
	(void) n;
	Fixed tmp(*this);
	tmp._value = this->_value++;
	return tmp;
}

Fixed	Fixed::operator -- (int n)
{
	(void) n; 
	Fixed tmp(*this);
	tmp._value = this->_value--;
	return tmp;
}

// max min functions

Fixed		&Fixed::min(Fixed &a, Fixed &b) { return (a > b) ? b : a; }
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) { return (a > b) ? b : a; }
Fixed		&Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }

// overload of the insertion << operator that inserts a floating-point representation fixed value
std::ostream& operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

