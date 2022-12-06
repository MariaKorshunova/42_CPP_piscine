/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:10:26 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 16:38:44 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_AFORM_HPP
#define CLASS_AFORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

public:
	AForm(const std::string& name = "form_noname", int signGrade = 1, int execGrade = 1);
	AForm(const AForm& form);
	AForm& operator= (const AForm& form);
	virtual ~AForm();

	const std::string	getName() const;
	bool				getIsIsigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	
	void	beSigned(Bureaucrat& bureaucrat);
	
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class NotSignedException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<< (std::ostream& out, const AForm& form);

#endif // CLASS_AFORM_HPP