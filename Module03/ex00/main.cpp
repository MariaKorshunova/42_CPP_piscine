/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:53:14 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 15:12:24 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main ( void )
{
	ClapTrap summer;
	ClapTrap rick("Rick");
	ClapTrap morty(summer);
	
	morty.setName("Morty");
	morty.setHitPoints(42);
	morty.setEnergyPoints(42);
	morty.setAttackDamage(1);
	
	rick.setHitPoints(21);
	rick.setEnergyPoints(21);
	rick.setAttackDamage(2);

	summer = rick;
	summer.setName("Summer");
	summer.setEnergyPoints(0);
	summer.setHitPoints(0);
	
	summer.attack("Rick");
	morty.attack("Rick");
	rick.takeDamage(morty.getAttackDamage());

	morty.attack("Summer");
	summer.takeDamage(morty.getAttackDamage());
	
	rick.beRepaired(42);
	summer.beRepaired(42);
	
	return 0;
}