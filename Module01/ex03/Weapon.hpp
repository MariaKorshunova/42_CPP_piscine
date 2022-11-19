/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:26:31 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 18:57:15 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon
{
private:
	std::string	_type;

public:
	Weapon();
	Weapon(std::string type);
	
	~Weapon();
	
	const std::string	&getType();
	void	setType(std::string type);
};

#endif