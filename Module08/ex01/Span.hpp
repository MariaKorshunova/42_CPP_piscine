/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:00:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/11 20:55:04 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_SPAN_HPP
#define CLASS_SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private:
	unsigned int		_size;
	std::vector<int>	_array;

public:
	Span(unsigned int size = 0);
	Span(const Span& span);
	Span& operator= (const Span& span);
	~Span();

	unsigned int	getSize() const;

	void	addNumber(int value);
	void	print();

	int	shortestSpan();
	int	longestSpan();
};


#endif // CLASS_SPAN_HPP