/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:16:10 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 17:09:53 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(const std::string& type): _type(type)
{
	std::cout << "Default Animal constructor called"<< std::endl;
}

Animal::Animal(const Animal& animal): _type(animal._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator= (const Animal& animal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this == &animal)
		return *this;
	_type = animal._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

const std::string& Animal::getType() const { return _type; }

void	Animal::setType(std::string& type) { _type = type; }

void	Animal::makeSound() const
{
	std::cout << _type << " says ???" << std::endl;
}