/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:51:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/21 16:26:08 by jmabel           ###   ########.fr       */
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

	bool	operator > (const Fixed &value) const;
	bool	operator < (const Fixed &value) const;
	bool	operator >= (const Fixed &value) const;
	bool	operator <= (const Fixed &value) const;
	bool	operator == (const Fixed &value) const;
	bool	operator != (const Fixed &value) const;

	Fixed	operator + (const Fixed &value) const;
	Fixed	operator - (const Fixed &value) const;
	Fixed	operator * (const Fixed &value) const;
	Fixed	operator / (const Fixed &value) const;

	Fixed	operator ++ ();
	Fixed	operator -- ();
	Fixed	operator ++ (int n);
	Fixed	operator -- (int n);

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

#endif