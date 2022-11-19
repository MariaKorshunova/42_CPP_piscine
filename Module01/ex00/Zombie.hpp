/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:07:50 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 15:16:25 by jmabel           ###   ########.fr       */
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

    ~Zombie( void );

    void    announce( void );
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif