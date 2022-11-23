/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:41:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 18:53:47 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap(const std::string name);

	ScavTrap(const ScavTrap &scavtrap);
	ScavTrap& operator= (const ScavTrap &scavtrap);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();
};

#endif