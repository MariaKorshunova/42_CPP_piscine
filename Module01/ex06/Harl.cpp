/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:56:25 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/20 18:38:48 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]\n" <<
				"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. " <<
				"I really do!\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]\n" <<
				"I cannot believe adding extra bacon costs more money. " <<
				"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" <<
				std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]\n" <<
				"I think I deserve to have some extra bacon for free. " <<
				"I’ve been coming for years whereas you started working here since last month.\n" <<
				std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]\n" <<
				"This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::insignificant( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
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
	_memberFunctions[4] = &Harl::insignificant;
}

Harl::~Harl()
{
}

void Harl::complain( std::string level )
{
	int	index = 4;
	
	index = !level.compare(_levels[0]) +
			!level.compare(_levels[1]) * 2 +
			!level.compare(_levels[2]) * 3 +
			!level.compare(_levels[3]) * 4 - 1;
	switch(index)
	{
		case 0:
			(this->*_memberFunctions[0])();
		case 1:
			(this->*_memberFunctions[1])();
		case 2:
			(this->*_memberFunctions[2])();
		case 3:
			(this->*_memberFunctions[3])();
			break ;
		default:
			(this->*_memberFunctions[4])();
			break ;
	}
}
