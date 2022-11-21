/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:03 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/21 17:35:07 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
private:
	Fixed _x;
	Fixed _y;
	
public:
	Point();
	Point(const float &x, const float &y);
	Point(const Point &point);
	const Point& operator=(const Point &point);
	~Point();

	const Fixed&	getX() const;
	const Fixed&	getY() const;

	void	setX(const Fixed& value);
	void	setY(const Fixed& value);
};

std::ostream& operator << (std::ostream &out, const Point &point);

#endif