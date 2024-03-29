/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:38:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 19:04:36 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_CLEAN		"\x1b[0m"

int	main(void)
{
	std::cout << COLOR_YELLOW "\nTest 1: create bureaucrat" COLOR_CLEAN << std::endl;
	Bureaucrat Rick("Rick", 150);
	Bureaucrat Morty("Morty", 5);
	Bureaucrat Summer("Summer", 1);
	std::cout << Rick;
	std::cout << Morty;
	std::cout << Summer;
	
	std::cout << COLOR_YELLOW "\nTest 2: Create form" COLOR_CLEAN << std::endl;
	ShrubberyCreationForm shrubbery("test");
	RobotomyRequestForm robotomy("test");
	PresidentialPardonForm pardon("test");
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;
	
	std::cout << COLOR_YELLOW "\nTest 3: Exec with low grade" COLOR_CLEAN << std::endl;
	try{ Rick.executeForm(shrubbery); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }
	try{ Rick.executeForm(robotomy); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }
	try{ Rick.executeForm(pardon); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }

	std::cout << COLOR_YELLOW "\nTest 4: Exec not signed form" COLOR_CLEAN << std::endl;
	try{ Morty.executeForm(shrubbery); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }
	try{ Morty.executeForm(robotomy); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }
	try{ Morty.executeForm(pardon); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }

	std::cout << COLOR_YELLOW "\nTest 5: Exec form" COLOR_CLEAN << std::endl;
	Summer.signForm(shrubbery);
	Summer.signForm(robotomy);
	Summer.signForm(pardon);
	std::cout << std::endl;
	try{ Morty.executeForm(shrubbery); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }
	std::cout << std::endl;
	try{ Morty.executeForm(robotomy); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }
	std::cout << std::endl;
	try{ Morty.executeForm(pardon); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }
}