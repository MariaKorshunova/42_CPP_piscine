/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:56:25 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 19:48:22 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. " <<
				"I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. " <<
				"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<
				std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. " <<
				"I’ve been coming for years whereas you started working here since last month." <<
				std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
	
	_memberFunctions[0] = &Harl::debug;
	_memberFunctions[1] = &Harl::info;
	_memberFunctions[2] = &Harl::warning;
	_memberFunctions[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::complain( std::string level )
{
	int index = !level.compare(_levels[0]) +
				!level.compare(_levels[1]) * 2 +
				!level.compare(_levels[2]) * 3 +
				!level.compare(_levels[3]) * 4 - 1;
	if (index < 0 || index > 3)
		return ;
	(this->*_memberFunctions[index])();
}
