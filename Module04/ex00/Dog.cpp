/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:16:10 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 20:02:54 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(const std::string& type): Animal(type)
{
	std::cout << "Default Dog constructor called"<< std::endl;
}

Dog::Dog(const Dog& dog): Animal(dog._type)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator= (const Dog& dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &dog)
		return *this;
	_type = dog._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << _type << " says woof" << std::endl;
}