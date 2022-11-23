/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:53:14 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 19:36:15 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main ( void )
{
	ClapTrap	rick("Rick");
	ScavTrap	morty("Morty");
	FragTrap	summer("Summer");

	rick.attack("Summer");
	summer.takeDamage(rick.getAttackDamage());
	
	summer.attack("Morty");
	morty.takeDamage(summer.getAttackDamage());
	
	summer.beRepaired(42);
	
	morty.guardGate();
	summer.highFivesGuys();
	
	return 0;
}