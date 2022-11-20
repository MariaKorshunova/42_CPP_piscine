/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:50:55 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/20 18:33:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class	Harl
{
private:
	
	void	(Harl::*_memberFunctions[5])(void );
	std::string _levels[4];
	
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void insignificant( void );
	
public:
	Harl();
	~Harl();

	void complain( std::string level );
};

#endif