/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:51:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/21 14:09:55 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
private:
	int	_value;
	static const int	_numberFractionalBits = 8;

public:
	Fixed();
	Fixed(const int	value);
	Fixed(const float value);
	
	Fixed(const Fixed &fixed);
	const Fixed& operator=(const Fixed &fixed);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

#endif