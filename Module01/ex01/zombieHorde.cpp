/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:39:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 16:52:08 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return NULL;

	Zombie	*hord = new Zombie[N];
	
	for (int i = 0; i < N; ++i)
		 hord[i].setName(name);
	
	return hord;
}