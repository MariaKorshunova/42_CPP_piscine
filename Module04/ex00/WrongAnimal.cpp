/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:16:10 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 17:43:24 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string& type): _type(type)
{
	std::cout << "Default WrongAnimal constructor called"<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal): _type(animal._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& animal)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this == &animal)
		return *this;
	_type = animal._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

const std::string& WrongAnimal::getType() const { return _type; }

void	WrongAnimal::setType(std::string& type) { _type = type; }

void	WrongAnimal::makeSound() const
{
	std::cout << _type << " says ???" << std::endl;
}