/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:19:18 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/11 16:51:10 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "easyfind.hpp"

#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_CLEAN		"\x1b[0m"

int	main(void)
{
	std::vector<int> arr;
	std::vector<int>::iterator it;

	std::cout << COLOR_YELLOW "\nTest 1: empty array" COLOR_CLEAN << std::endl;
	try { it = easyfind(arr, 42); }
	catch(std::exception& e) { std::cerr << e.what() << std::endl; }

	std::cout << COLOR_YELLOW "\nFill array" COLOR_CLEAN << std::endl;
	for (int i = 1; i <= 21; i++)
		arr.push_back(i);
    for (int i = 0; i < static_cast<int>(arr.size()); i++)
		std::cout << arr.at(i) << ' ';
	
	std::cout << COLOR_YELLOW "\nTest 2: No occurrence is found" COLOR_CLEAN << std::endl;
	try { it = easyfind(arr, 42); }
	catch(std::exception& e) { std::cerr << e.what() << std::endl; }

	std::cout << COLOR_YELLOW "\nTest 3: return occurence" COLOR_CLEAN << std::endl;
	try
	{
		it = easyfind(arr, 21);
		std::cout << *it << std::endl;
	}
	catch(std::exception& e) { std::cerr << e.what() << std::endl; }

	return 0;
}