/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/28 16:47:00 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ANIMAL_HPP
#define CLASS_ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string	_type;
	Animal(const std::string& type = "Animal");

public:
	Animal(const Animal& animal);
	Animal& operator= (const Animal& animal);
	virtual ~Animal();

	const std::string&	getType() const;
	void	setType(std::string& type);
	
	virtual void	makeSound() const = 0;
};

#endif // CLASS_ANIMAL_HPP