/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:53:27 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 18:57:21 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap ("", 100, 50, 20)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap Constructor with name as parameter called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap)				
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	setName(scavtrap.getName());
	setHitPoints(scavtrap.getHitPoints());
	setEnergyPoints(scavtrap.getEnergyPoints());
	setAttackDamage(scavtrap.getAttackDamage());	
}

ScavTrap&	ScavTrap::operator= (const ScavTrap &scavtrap)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this == &scavtrap)
		return *this;
	setName(scavtrap.getName());
	setHitPoints(scavtrap.getHitPoints());
	setEnergyPoints(scavtrap.getEnergyPoints());
	setAttackDamage(scavtrap.getAttackDamage());
	return *this;		
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;	
}

void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0 || getEnergyPoints()  <= 0)
	{
		std::cout 	<< COLOR_GREY "ScavTrap " << getName() <<  " can't attack " <<
			 		target << ", becouse has no energy or no hit points." << std::endl;
		printStatus();
		std::cout << COLOR_CLEAN << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout	<< COLOR_RED "ScavTrap " << getName() <<  " attacks " <<
			 	target << ", causing " << getAttackDamage() << " points of damage!" <<
			 	std::endl;
	printStatus();
	std::cout << COLOR_CLEAN << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout 	<< COLOR_BLUE "ScavTrap is now in Gate keeper mode." <<
				COLOR_CLEAN << std::endl;
}