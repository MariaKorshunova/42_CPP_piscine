/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:01:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/06 17:43:01 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BUREAUCRAT_HPP
#define CLASS_BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int	_grade;

public:
	Bureaucrat(const std::string& name = "bureaucrat", int grade = 150);
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat& operator= (const Bureaucrat& bureaucrat);
	~Bureaucrat();

	const std::string&	getName() const;
	int getGrade() const;

	void	setGrade(int grade);

	void	incrementBureaucratGrade();
	void	decrementBureaucratGrade();
	
	void	signForm(AForm& form);
	void	executeForm(AForm const & form);
	
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

std::ostream& operator<< (std::ostream& out, const Bureaucrat& bureaucrat);

#endif // CLASS_BUREAUCRAT_HPP
