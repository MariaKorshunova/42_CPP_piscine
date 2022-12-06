/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:31 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 18:59:37 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PRESIDENTIALPARDONFORM_HPP
#define CLASS_PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	std::string	_target;

public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& form);
	PresidentialPardonForm& operator= (const PresidentialPardonForm& form);
	~PresidentialPardonForm();

	const std::string	getTarget() const;
	void				setTarget(std::string target);
	
	virtual void	execute(Bureaucrat const & executor) const;
};

#endif // CLASS_PRESIDENTIALPARDONFORM_HPP