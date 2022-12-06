/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:40 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 19:01:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
					AForm("PresidentialPardonForm", 25, 5),
					_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form):
					AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
					_target(form._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& form)
{
	if (this == &form)
		return *this;
	static_cast<AForm&>(*this) = form;
	_target = form._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string	PresidentialPardonForm::getTarget() const { return _target; }

void	PresidentialPardonForm::setTarget(std::string target) { _target = target; }

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}