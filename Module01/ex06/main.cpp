/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:28:32 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/20 18:33:28 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_CLEAN "\x1b[0m"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << COLOR_RED "Invalid number of arguments" COLOR_CLEAN << std::endl;
		return 1;
	}
	
	Harl	harl; 
	harl.complain(argv[1]);
	return 0;
}