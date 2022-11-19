/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:07:50 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 16:50:27 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string _name;

public:
	Zombie( std::string name );
    Zombie();
    ~Zombie( void );

	void	setName(std::string name);
    
	std::string	getName();
	
    void    announce( void );
};

Zombie*	zombieHorde( int N, std::string name );

#endif