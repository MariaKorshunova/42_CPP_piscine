/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:24:02 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/09 20:41:35 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ARRAY_HPP
#define CLASS_ARRAY_HPP

#include <exception>

template <class T>
class Array
{
private:
	T*				_data;
	unsigned int	_len;
	
public:
	Array();
	Array(unsigned int len);
	Array(const Array& arr);
	T& operator= (const Array& arr);
	~Array();

	T& operator[] (unsigned int index);
	
	unsigned int size() const;
	
	class OutOfRange: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#include "Array.tpp"

#endif //CLASS_ARRAY_HPP
