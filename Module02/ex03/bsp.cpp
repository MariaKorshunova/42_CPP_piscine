/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:44:24 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/21 19:14:48 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	vectorDot(const Point& a, const Point& b, const Point& p)
{
	return (a.getX() - p.getX()) * (b.getY() - a.getY()) -
		((b.getX() - a.getX()) * (a.getY() - p.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed fixedNull;
	
	Fixed	ab(vectorDot(a, b, point));
	Fixed	bc(vectorDot(b, c, point));
	Fixed	ca(vectorDot(c, a, point));
	
	if (((ab > fixedNull) && (bc > fixedNull) && (ca > fixedNull)) ||
		((ab < fixedNull) && (bc < fixedNull) && (ca < fixedNull)) )
		return true ;
	return false;
}
