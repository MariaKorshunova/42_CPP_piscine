/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:50:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 20:55:56 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
	ClapTrap("_clap_name", 100, 50, 30), _name("")
{
	std::cout<< "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : 
	 ClapTrap(name + "_clap_name", 100, 50, 30), _name(name)
{
	std::cout<< "DiamondTrap constructor with name as parameter called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;	
}


const	std::string&	DiamondTrap::getName() const { return _name; }

void	DiamondTrap::attack(const std::string& target) { ScavTrap::attack(target); }

void	DiamondTrap::whoAmI()
{
	std::cout 	<< COLOR_CYAN "DiamondTrap`s name: " << getName() << 
				"\nClapTrap`s name: " << ClapTrap::getName() <<
				COLOR_CLEAN << std::endl;
}
