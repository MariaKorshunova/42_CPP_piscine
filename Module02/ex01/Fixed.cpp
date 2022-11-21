/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:06:10 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/21 14:14:14 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor
Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// int constructor
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value * (1 << _numberFractionalBits);
}

// float constructor
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = std::roundf(value * (1 << _numberFractionalBits));
}

// copy constructor
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = fixed.getRawBits();
}

//copy assignment operator overload
const	Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return *this;
	this->_value = fixed.getRawBits();
	return *this;
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

// overload of the insertion << operator that inserts a floating-point representation fixed value
std::ostream& operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}