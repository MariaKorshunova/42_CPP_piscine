/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:18:41 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/04 22:43:19 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade):
					_name(name), _grade(grade)
{
	if (_grade <= 0)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat):
					_name(bureaucrat._name), _grade(bureaucrat._grade)
{
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& bureaucrat)
{
	if (this == &bureaucrat)
		return *this;
	_grade = bureaucrat._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string&	Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::setGrade(int grade)
{
	if (grade <= 0)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

void	Bureaucrat::incrementBureaucratGrade() { setGrade(_grade - 1); }
void	Bureaucrat::decrementBureaucratGrade() { setGrade(_grade + 1); }

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr 	<< getName() << " couldn't sign " << form.getName() <<
					" because " << e.what() << std::endl;
	}	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: too high bureaucrat grade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: too low bureaucrat grade");
}

std::ostream& operator<< (std::ostream& out, const Bureaucrat& bureaucrat)
{
	return out 	<< bureaucrat.getName() << ", bureaucrat grade "
				<< bureaucrat.getGrade() << std::endl;
}
