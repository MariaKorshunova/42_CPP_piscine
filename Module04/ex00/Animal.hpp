/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 17:34:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ANIMAL_HPP
#define CLASS_ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string	_type;

public:
	Animal(const std::string& type = "Animal");
	Animal(const Animal& animal);
	Animal& operator= (const Animal& animal);
	virtual ~Animal();

	const std::string&	getType() const;

	void	setType(std::string& type);
	
	virtual void	makeSound() const;
};


#endif // CLASS_ANIMAL_HPP