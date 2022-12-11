/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:11:54 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/11 20:57:06 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size): _size(size)
{
}

Span::Span(const Span& span): _size(span._size), _array(span._array)
{
}

Span& Span::operator= (const Span& span)
{
	if (this == &span)
		return *this;
	_size = span._size;
	_array = span._array;
	return *this;
}

Span::~Span()
{
}

unsigned int	Span::getSize() const { return _size; }

void	Span::addNumber(int value)
{
	if (_array.size() == _size)
		throw std::length_error("Array is full");
	_array.push_back(value);
}

int	Span::shortestSpan()
{
	if (_array.size() < 2)
		throw std::length_error("Can't find shortestSpan. Size of array less than 2");
	std::sort(_array.begin(), _array.end());
	int shortestSpan = _array[1] - _array[0];
	for(std::vector<int>::iterator it = _array.begin() + 1;
			it != _array.end() - 1; it++)
	{
		if (*(it + 1) - *it < shortestSpan)
			shortestSpan = *(it + 1) - *it;
	}
	return shortestSpan;
}

int	Span::longestSpan()
{
	if (_array.size() < 2)
		throw std::length_error("Can't find longestSpan. Size of array less than 2");
	std::vector<int>::iterator itmin = std::min_element(_array.begin(), _array.end());
	std::vector<int>::iterator itmax = std::max_element(_array.begin(), _array.end());
	return (*itmax - *itmin);
}

void	Span::print()
{
	for(std::vector<int>::iterator it = _array.begin();
			it != _array.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
}
