/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:19:48 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 19:32:56 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("", 100, 100, 30)
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Constructor with name as parameter called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &fragtrap)				
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	setName(fragtrap.getName());
	setHitPoints(fragtrap.getHitPoints());
	setEnergyPoints(fragtrap.getEnergyPoints());
	setAttackDamage(fragtrap.getAttackDamage());	
}

FragTrap&	FragTrap::operator= (const FragTrap &fragtrap)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this == &fragtrap)
		return *this;
	setName(fragtrap.getName());
	setHitPoints(fragtrap.getHitPoints());
	setEnergyPoints(fragtrap.getEnergyPoints());
	setAttackDamage(fragtrap.getAttackDamage());
	return *this;		
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;	
}

void	FragTrap::attack(const std::string& target)
{
	if (getHitPoints() <= 0 || getEnergyPoints()  <= 0)
	{
		std::cout 	<< COLOR_GREY "FragTrap " << getName() <<  " can't attack " <<
			 		target << ", becouse has no energy or no hit points." << std::endl;
		printStatus();
		std::cout << COLOR_CLEAN << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout	<< COLOR_RED "FragTrap " << getName() <<  " attacks " <<
			 	target << ", causing " << getAttackDamage() << " points of damage!" <<
			 	std::endl;
	printStatus();
	std::cout << COLOR_CLEAN << std::endl;
}

void 	FragTrap::highFivesGuys(void)
{
	std::cout 	<< COLOR_MAGENDA "FragTap " <<
				getName() << " says: \"High fives, dude!\"" <<
				COLOR_CLEAN << std::endl;
}