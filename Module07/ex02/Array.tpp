/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:45:48 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/09 20:42:54 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _data(new T[0]), _len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int len): _data(new T[len]), _len(len)
{
}
template <typename T>
Array<T>::Array(const Array& arr): _data(new T[arr._len]), _len(arr._len)
{
	for (unsigned int i = 0; i < _len; i++)
		_data[i] = arr._data[i];
}

template <typename T>
T& Array<T>::operator= (const Array& arr)
{
	if (this == arr)
		return *this;
	delete[] _data;
	_len = arr._len;
	for (unsigned int i = 0; i < _len; i++)
		_data[i] = arr._data[i];
	return *this;	
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T& Array<T>::operator[] (unsigned int index)
{
	if (index < 0 || index >= _len)
		throw OutOfRange();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const { return _len; }

template <typename T>
const char* Array<T>::OutOfRange::what() const throw()
{
	return "Index out of range";
}