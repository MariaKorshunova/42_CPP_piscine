/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:22:24 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 19:53:08 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_INTERN_HPP
#define CLASS_INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	AForm*	(Intern::*_memberFunctions[3])(std::string& );
	std::string	_forms[3];
	
	AForm*	shrubbery(std::string& target);
	AForm*	robotomy(std::string& target);
	AForm*	pardon(std::string& target);
	
public:
	Intern();
	Intern(const Intern& intern);
	Intern& operator= (const Intern& intern);
	~Intern();
	
	AForm*	makeForm(std::string form, std::string target);

	class NotExistedForm: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif //CLASS_INTERN_HPP