/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:06:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 17:07:34 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N;
	std::string	name;

	std::cout << "Enter name of zombies: ";
	std::cin >> name;
	if (std::cin.eof())
		exit(1);
	
	std::cout << "Enter amount of zombies: ";
	std::cin >> N;
	std::cout << std::endl;

	if (N < 0)
	{
		std::cout << "Amount of zombies should be a positive number" << std::endl;
		return 0;
	}
	
	Zombie *hord = zombieHorde(N, name);
	if (!hord)
		return 0;
	
	for (int i = 0; i < N; ++i)
		hord[i].announce();
	
	delete[] hord;
	hord = 0;
	
	return 0;
}
