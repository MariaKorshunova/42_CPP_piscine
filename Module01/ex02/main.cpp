/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:06:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 18:16:15 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string("HI THIS IS BRAIN");
	std::string *stringPTR = &string; // pointer
	std::string &stringREF = string; // reference
	
	std::cout << "The memory address of the string variable: " << &string <<
				"\nThe memory address held by stringPTR     : " << stringPTR <<
				"\nThe memory address held by stringREF     : " << &stringREF <<
				"\nThe value of the string variable         : " << string <<
				"\nThe value pointed to by stringPTR        : " << *stringPTR <<
				"\nThe value pointed to by stringREF        : " << stringREF << std::endl;
	
	return 0;
}
