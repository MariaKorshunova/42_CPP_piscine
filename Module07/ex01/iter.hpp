/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:55:48 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/09 16:14:07 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	iter(T* arr, unsigned int len, void(*f)(T*))
{
	if (!arr)
		return ;
	for (unsigned int i = 0; i < len; i++)
		f(&arr[i]);
}