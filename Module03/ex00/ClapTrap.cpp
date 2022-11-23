/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:21:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 15:11:04 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

ClapTrap::ClapTrap(): 	_name("ClapTrap"),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name):
						_name(name),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0)
{
	std::cout << "Constructor with name as parameter called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap):
						_name(claptrap.getName()),
						_hitPoints(claptrap.getHitPoints()),
						_energyPoints(claptrap.getEnergyPoints()),
						_attackDamage(claptrap.getAttackDamage())						
						
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &claptrap)
		return *this;
	_name = claptrap.getName();
	_hitPoints = claptrap.getHitPoints();
	_energyPoints = claptrap.getEnergyPoints();
	_attackDamage = claptrap.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

const std::string&	ClapTrap::getName() const { return _name; }
int ClapTrap::getHitPoints() const { return _hitPoints; }
int ClapTrap::getEnergyPoints() const { return _energyPoints; }
int ClapTrap::getAttackDamage() const { return _attackDamage; }

void	ClapTrap::setName(const std::string name) { _name = name; }
void	ClapTrap::setHitPoints(const int hitPoints) { _hitPoints = hitPoints >= 0 ? hitPoints : 0; }
void	ClapTrap::setEnergyPoints(const int energyPoints) { _energyPoints = energyPoints >= 0 ? energyPoints : 0; }
void	ClapTrap::setAttackDamage(const int attackDamage) { _attackDamage = attackDamage >= 0 ? attackDamage : 0; }

void	ClapTrap::printStatus()
{
	std::cout 	<< "Current status claptrap " << _name <<
				":\n\thit points: " << _hitPoints <<
				"\n\tenergy points: " << _energyPoints <<
				"\n\tattack damage: " << _attackDamage <<
				std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints  <= 0)
	{
		std::cout 	<< COLOR_GREY "ClapTrap " << _name <<  " can't attack " <<
			 		target << ", becouse has no energy or no hit points." << std::endl;
		printStatus();
		std::cout << COLOR_CLEAN << std::endl;
		return ;
	}
	setEnergyPoints(_energyPoints - 1);
	std::cout	<< COLOR_RED "ClapTrap " << _name <<  " attacks " <<
			 	target << ", causing " << _attackDamage << " points of damage!" <<
			 	std::endl;
	printStatus();
	std::cout << COLOR_CLEAN << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << COLOR_GREY "ClapTrap " << _name << " is already dead." << std::endl;
		printStatus();
		std::cout << COLOR_CLEAN << std::endl;
		return ;
	}
	setHitPoints(_hitPoints - amount);
	std::cout << COLOR_YELLOW "ClapTrap " << _name <<  " lose " <<
			amount << " hit points." << std::endl;
	printStatus();
	std::cout << COLOR_CLEAN << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints  <= 0)
	{
		std::cout 	<< COLOR_GREY "ClapTrap " << _name <<  " can't repair itself, " <<
			 		", becouse has no energy or no hit points." << std::endl;
		printStatus();
		std::cout << COLOR_CLEAN << std::endl;
		return ;
	}
	setEnergyPoints(_energyPoints - 1);
	setHitPoints(_hitPoints + amount);
	std::cout	<< COLOR_GREEN "ClapTrap " << _name << 
				" repairs itself with amount " << amount <<
			 	std::endl;
	printStatus();
	std::cout << COLOR_CLEAN << std::endl;	
}