/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:51:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/20 22:29:50 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
private:
	int	_value;
	static const int	_numberFractionalBits = 8;

public:
	Fixed(); // default constructor
	Fixed(const Fixed &fixed); // copy constructor
	const Fixed& operator=(const Fixed &fixed); //copy assignment operator overload
	~Fixed(); // destructor

	int		getRawBits( void ) const; // returns the raw value of the fixed-point value
	void	setRawBits( int const raw ); //sets the raw value of the fixed-point number
};

#endif