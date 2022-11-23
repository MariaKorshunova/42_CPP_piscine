/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:06 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 18:55:38 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

class	ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage);

	ClapTrap(const ClapTrap &claptrap);
	ClapTrap& operator= (const ClapTrap &claptrap);
	
	~ClapTrap();

	const std::string&	getName() const;
	int					getHitPoints() const;
	int					getEnergyPoints() const;
	int					getAttackDamage() const;

	void	setName(const std::string name);
	void	setHitPoints(const int hitPoints);
	void	setEnergyPoints(const int energyPoints);
	void	setAttackDamage(const int attackDamage);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	printStatus();
};

#endif