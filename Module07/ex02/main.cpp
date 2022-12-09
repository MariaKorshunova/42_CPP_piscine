/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:33:48 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/09 22:00:30 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int	main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int	random_variable;
	Array<int>	arr(42);
	for (int i = 0; i < 42; i++)
	{
		random_variable = std::rand() % 10;
		arr[i] = random_variable;
	}
	for (int i = 0; i < 42; i++)
		std::cout << arr[i] << " ";
	std::cout << "\nsize of array: " << arr.size() << std::endl;
	try {std::cout << arr[-1];}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	return 0;
}