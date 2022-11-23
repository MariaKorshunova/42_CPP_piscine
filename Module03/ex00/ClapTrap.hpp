/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:06 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 15:05:19 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

	void		printStatus();

public:
	ClapTrap();
	ClapTrap(const std::string name);

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
};

#endif