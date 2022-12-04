/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:10:26 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/04 22:41:53 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_FORM_HPP
#define CLASS_FORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

public:
	Form(const std::string& name = "form_noname", int signGrade = 1, int execGrade = 1);
	Form(const Form& form);
	Form& operator= (const Form& form);
	~Form();

	const std::string	getName() const;
	bool				getIsIsigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	
	void	beSigned(Bureaucrat& bureaucrat);
	
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
};

std::ostream& operator<< (std::ostream& out, const Form& form);

#endif // CLASS_FORM_HPP