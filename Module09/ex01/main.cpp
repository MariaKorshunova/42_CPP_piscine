/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:33:26 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/13 18:55:51 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
		std::cerr 	<< "Error" <<  std::endl;
		return (1);
	}
	try 
	{
		RPN rpn(static_cast<std::string>(argv[1])); 
		rpn.calculation();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
