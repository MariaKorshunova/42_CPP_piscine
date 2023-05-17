/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:05:00 by jmabel            #+#    #+#             */
/*   Updated: 2023/05/17 15:43:53 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

#define COLOR_RED "\x1b[31m"
#define RESET "\x1b[0m"

int main(int argc, char **argv)
{
    if (argc != 2) {
		std::cerr 	<< COLOR_RED "btc: Error: invalid number of arguments. Program must take a file as argument." RESET
					<< std::endl;
		return (1);
	}

	try {
		BitcoinExchange btc(static_cast<std::string>(argv[1]));
		btc.exchange();
	} catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << RESET << std::endl;
	}

	// system("leaks btc");
	// std::cout << "test: " << std::isdigit(' ') << std::endl;
    return (0);
}