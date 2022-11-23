/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:53:14 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 18:58:39 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main ( void )
{
	ClapTrap rick("Rick");
	ScavTrap bot1("BotScavTrap1");
	ScavTrap bot2(bot1);
	ScavTrap bot3;

	bot3 = bot2;
	
	bot2.setName("BotScavTrap2");
	bot3.setName("BotScavTrap3");
	
	bot1.attack("BotScavTrap2");
	bot2.takeDamage(bot1.getAttackDamage());
	bot2.beRepaired(5);

	bot3.guardGate();
	
	return 0;
}