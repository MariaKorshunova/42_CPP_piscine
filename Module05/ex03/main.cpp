/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:38:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 20:47:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
	
	std::cout << COLOR_YELLOW "\nTest 2: Create form by intern" COLOR_CLEAN << std::endl;
	Intern someRandomIntern;
	AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "Ford");
	AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur");
	std::cout << *shrubbery;
	std::cout << *robotomy;
	std::cout << *pardon;
	
	std::cout << COLOR_YELLOW "\nTest 3: Exec form" COLOR_CLEAN << std::endl;
	Summer.signForm(*shrubbery);
	Summer.signForm(*robotomy);
	Summer.signForm(*pardon);
	std::cout << std::endl;
	try{ Morty.executeForm(*shrubbery); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }
	std::cout << std::endl;
	try{ Morty.executeForm(*robotomy); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }
	std::cout << std::endl;
	try{ Morty.executeForm(*pardon); }
	catch (std::exception &e){ std::cerr << e.what() << std::endl; }

	delete shrubbery;
	delete robotomy;
	delete pardon;
}