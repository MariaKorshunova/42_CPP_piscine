/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:05:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 18:01:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_SHRUBBERYCREATIONFORM_HPP
#define CLASS_SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	std::string	_target;

public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& form);
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm& form);
	~ShrubberyCreationForm();

	const std::string	getTarget() const;
	void				setTarget(std::string target);
	
	virtual void	execute(Bureaucrat const & executor) const;

	class FileOpenException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif // CLASS_SHRUBBERYCREATIONFORM_HPP