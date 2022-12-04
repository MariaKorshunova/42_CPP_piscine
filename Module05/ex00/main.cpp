/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:38:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/04 17:49:17 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_CLEAN		"\x1b[0m"

int	main(void)
{
	std::cout << COLOR_YELLOW "\nTest 1: create bureaucrat" COLOR_CLEAN << std::endl;
	Bureaucrat Rick("Rick", 150);
	std::cout << Rick;
	try{
		Bureaucrat Morty("Morty", 0); //GradeTooHighException
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Bureaucrat Morty("Morty", 151); //GradeTooLowException
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << COLOR_YELLOW "\nTest 2: increament and  decrement" COLOR_CLEAN << std::endl;
	try{
		Rick.decrementBureaucratGrade(); // 150 + 1 = 151 GradeTooLowException
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Rick.incrementBureaucratGrade(); // 150 - 1 = 149
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << Rick;
	Rick.setGrade(2);
	std::cout << Rick;
	Rick.incrementBureaucratGrade();
	std::cout << Rick;
	try{
		Rick.incrementBureaucratGrade(); // 0 - 1 = -1 GradeTooHighException
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}