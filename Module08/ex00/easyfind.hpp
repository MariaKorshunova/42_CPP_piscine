/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:05:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/11 18:09:44 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_EASYFIND_HPP
#define CLASS_EASYFIND_HPP

#include <exception>

template <typename T>
typename T::iterator	easyfind(T& array, int value)
{
	if (array.empty())
		throw std::range_error("Empty array");
	typename T::iterator i;
	i = std::find(array.begin(), array.end(), value);
	if (i == array.end())
		throw std::runtime_error("No occurrence is found");
	return i;
}

#endif