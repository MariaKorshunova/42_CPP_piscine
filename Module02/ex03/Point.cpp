/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:46:57 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/21 17:36:22 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{   
}

Point::Point(const float &x, const float &y): _x(x), _y(y)
{
}

Point::Point(const Point &point) { *this = point; }

const Point& Point::operator =(const Point &point)
{
	if (this == &point)
		return *this;
	_x = point.getX();
	_y = point.getY();
}

Point::~Point()
{
}

const Fixed&	Point::getX() const { return _x; }
const Fixed&	Point::getY() const { return _y; }

void	Point::setX(const Fixed& value){ _x = value; }
void	Point::setY(const Fixed& value){ _y = value; }

std::ostream& operator << (std::ostream &out, const Point &point)
{
	out << "(" << point.getX() << "," << point.getY() << ")";
	return out;
}