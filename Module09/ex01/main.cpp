/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:33:26 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/12 19:18:29 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

#define COLOR_RED "\x1b[31m"
#define RESET "\x1b[0m"

int main(int argc, char **argv)
{
    if (argc != 2) {
		std::cerr 	<< COLOR_RED "RPN: Error: invalid number of arguments. " 
					<< "Program must take a string with inverted Polish mathematical expression" RESET
					<< std::endl;
		return (1);
	}
	try 
	{
		RPN rpn(static_cast<std::string>(argv[1])); 
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << RESET << '\n';
	}

	return (0);
}
