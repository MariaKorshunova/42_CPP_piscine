/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:06:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 16:30:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	Rick("Rick");
	Zombie	*Morty;

	Morty = newZombie("Morty");
	Morty->announce();
	Rick.announce();
	randomChump("Summer");
	delete Morty;
	Morty = nullptr; 
	return 0;
}
