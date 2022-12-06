/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:59:05 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 18:59:41 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ROBOTOMYREQUESTFORM_HPP
#define CLASS_ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	std::string	_target;

public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& form);
	RobotomyRequestForm& operator= (const RobotomyRequestForm& form);
	~RobotomyRequestForm();

	const std::string	getTarget() const;
	void				setTarget(std::string target);
	
	virtual void	execute(Bureaucrat const & executor) const;
};

#endif // CLASS_ROBOTOMYREQUESTFORM_HPP