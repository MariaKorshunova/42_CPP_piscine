/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:15:11 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 17:46:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
					AForm("ShrubberyCreationForm", 145, 137),
					_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form):
					AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
					_target(form._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& form)
{
	if (this == &form)
		return *this;
	static_cast<AForm&>(*this) = form;
	_target = form._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string	ShrubberyCreationForm::getTarget() const { return _target; }

void	ShrubberyCreationForm::setTarget(std::string target) { _target = target; }

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::ofstream	outfile(_target + "_shrubbery ");
	if (!outfile.is_open())
		throw FileOpenException();
	outfile << 	"    oxoxoo    ooxoo\n" 	<<
				"  ooxoxo oo  oxoxooo\n"	<<
				" oooo xxoxoo ooo ooox\n"	<<
				" oxo o oxoxo  xoxxoxo\n"	<<
				"  oxo xooxoooo o ooo\n"	<<
				"    ooo\\oo\\  /o/o\n"		<<
				"        \\  \\/ /\n"		<<
				"         |   /\n"			<<
				"         |  |\n"			<<
				"         | D|\n"			<<
				"         |  |\n"			<<
				"         |  |\n"			<<
				"  ______/____\\____\n";
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return ("open file error");
}