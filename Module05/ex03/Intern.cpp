/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:29:48 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 20:43:42 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	_forms[0] = "shrubbery creation";
	_forms[1] = "robotomy request";
	_forms[2] = "presidential pardon";

	_memberFunctions[0] = &Intern::shrubbery;
	_memberFunctions[1] = &Intern::robotomy;
	_memberFunctions[2] = &Intern::pardon;
}

Intern::Intern(const Intern& intern)
{
	(void) intern;
}

Intern& Intern::operator= (const Intern& intern)
{
	(void) intern;
	return *this;
}

Intern::~Intern()
{
}

AForm*	Intern::shrubbery(std::string& target) { return new ShrubberyCreationForm(target); }
AForm*	Intern::robotomy(std::string& target) { return new RobotomyRequestForm(target); }
AForm*	Intern::pardon(std::string& target) { return new PresidentialPardonForm(target); }

AForm*	Intern::makeForm(std::string form, std::string target)
{
	int index = !form.compare(_forms[0]) + 
				!form.compare(_forms[1]) * 2 + 
				!form.compare(_forms[2]) * 3 - 1;
	if (index < 0 || index > 3)
		throw NotExistedForm();
	else
	std::cout << "Intern creates " << form << std::endl;
	return (this->*_memberFunctions[index])(target);
}

const char* Intern::NotExistedForm::what() const throw()
{
	return ("form doesn't exist,");
}
