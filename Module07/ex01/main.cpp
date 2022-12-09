/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:07:56 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/09 16:19:22 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_CLEAN		"\x1b[0m"

template <typename T>
void	print(T* elem) { std::cout << *elem << std::endl; }

int	main(void)
{
	{
		std::cout << COLOR_YELLOW "Test 1: int array " << COLOR_CLEAN << std::endl;
		int arr[] = {1, 2, 3, 4, 5};
		iter(arr, 5, print);
	}
	{
		std::cout << COLOR_YELLOW "Test 2: char array " << COLOR_CLEAN << std::endl;
		char arr[] = "abcde";
		iter(arr, 5, print);
	}
	{
		std::cout << COLOR_YELLOW "Test 3: string array " << COLOR_CLEAN << std::endl;
		std::string arr[] = {"Hello", "world", "!"};
		iter(arr, 3, print);
	}
	return 0;
}