/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:44:50 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 20:20:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;

public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	
	DiamondTrap(const DiamondTrap &diamondtrap);
	DiamondTrap& operator= (const DiamondTrap &diamondtrap);
	~DiamondTrap();

	const	std::string&	getName() const;
	
	void	attack(const std::string &target);
	void	whoAmI();
};

#endif