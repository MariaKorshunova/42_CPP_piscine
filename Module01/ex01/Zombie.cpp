/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:12:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 16:51:10 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ): _name(name) 
{
}

Zombie::Zombie()
{
}

Zombie::~Zombie( void )
{
	std::cout << _name << " is destroyed" << std::endl;
}

void	Zombie::setName(std::string name) { _name = name; }

std::string	Zombie::getName() { return _name; }

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

