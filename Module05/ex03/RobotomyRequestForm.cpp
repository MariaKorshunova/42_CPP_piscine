/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:01:49 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 19:00:01 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
					AForm("RobotomyRequestForm", 72, 45),
					_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form):
					AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
					_target(form._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& form)
{
	if (this == &form)
		return *this;
	static_cast<AForm&>(*this) = form;
	_target = form._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string	RobotomyRequestForm::getTarget() const { return _target; }

void	RobotomyRequestForm::setTarget(std::string target) { _target = target; }

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

	AForm::execute(executor);
	std::cout << "***** DRILLING NOISES *****\n";
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	int random_variable = std::rand();
	if (random_variable % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << ": the robotomy failed." << std::endl;
}
