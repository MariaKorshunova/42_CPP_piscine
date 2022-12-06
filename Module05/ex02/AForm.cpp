/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:33:21 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 17:31:57 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade):
			_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_isSigned = false;
	if (_signGrade <= 0 || _execGrade <= 0)
		throw GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& form):
			_name(form._name), _signGrade(form._signGrade),  _execGrade(form._execGrade)
{
}

AForm& AForm::operator= (const AForm& form)
{
	if (this == &form)
		return *this;
	_isSigned = form._isSigned;
	return *this;
}

AForm::~AForm()
{
}

const std::string	AForm::getName() const { return _name; }
bool				AForm::getIsIsigned() const { return _isSigned; }
int					AForm::getSignGrade() const { return _signGrade; }
int					AForm::getExecGrade() const { return _execGrade; }

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	else if (_isSigned == false)
		throw NotSignedException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("too high bureaucrat grade");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("too low bureaucrat grade");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("form is not signed");
}

std::ostream& operator<< (std::ostream& out, const AForm& form)
{
	return out 	<< "Form " << form.getName() <<
			 	":\n\tis signed: " << form.getIsIsigned() <<
				"\n\tsign grade: " << form.getSignGrade() <<
				"\n\texec grade: " << form.getExecGrade() <<
				std::endl;
}