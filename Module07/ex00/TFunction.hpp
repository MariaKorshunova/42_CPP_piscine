/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TFunction.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:45:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/08 20:19:53 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap(T& a, T& b)
{
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T&	min(T& a, T& b) { return (a < b)? a: b; }

template <typename T>
T&	max(T& a, T& b) { return (a > b)? a: b; }