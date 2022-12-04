/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:33:21 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/04 22:43:25 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade):
			_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_isSigned = false;
	if (_signGrade <= 0 || _execGrade <= 0)
		throw GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& form):
			_name(form._name), _signGrade(form._signGrade),  _execGrade(form._execGrade)
{
}

Form& Form::operator= (const Form& form)
{
	if (this == &form)
		return *this;
	_isSigned = form._isSigned;
	return *this;
}

Form::~Form()
{
}

const std::string	Form::getName() const { return _name; }
bool				Form::getIsIsigned() const { return _isSigned; }
int					Form::getSignGrade() const { return _signGrade; }
int					Form::getExecGrade() const { return _execGrade; }

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("too high bureaucrat grade");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("too low bureaucrat grade");
}

std::ostream& operator<< (std::ostream& out, const Form& form)
{
	return out 	<< "Form " << form.getName() <<
			 	":\n\tis signed: " << form.getIsIsigned() <<
				"\n\tsign grade: " << form.getSignGrade() <<
				"\n\texec grade: " << form.getExecGrade() <<
				std::endl;
}