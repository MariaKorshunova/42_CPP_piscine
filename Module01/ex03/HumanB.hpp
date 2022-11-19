/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:41:43 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 19:04:14 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon	*_weapon;
	std::string	_name;

public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &weapon);
	
	void	attack();
};

#endif