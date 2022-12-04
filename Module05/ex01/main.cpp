/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:38:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/04 22:42:19 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_CLEAN		"\x1b[0m"

int	main(void)
{
	std::cout << COLOR_YELLOW "\nTest 1: create bureaucrat" COLOR_CLEAN << std::endl;
	Bureaucrat Rick("Rick", 150);
	std::cout << Rick;
	
	std::cout << COLOR_YELLOW "\nTest 2: create form" COLOR_CLEAN << std::endl;
	Form form_0("form_0", 2, 3);
	std::cout << form_0;
	
	try{
		Form form_error("Form error", 0, 5); //GradeTooHighException
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

		try{
		Form form_error("Form error", 1, 151); //GradeTooLowException
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << COLOR_YELLOW "\nTest 3: sign form" COLOR_CLEAN << std::endl;
	try{
		Rick.signForm(form_0);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Rick.setGrade(1);
	std::cout << Rick;
	Rick.signForm(form_0);
	std::cout << form_0;
}