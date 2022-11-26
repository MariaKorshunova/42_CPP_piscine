/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:16:10 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 20:29:57 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(const std::string& type): Animal(type)
{
	std::cout << "Default Cat constructor called"<< std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& cat): Animal(cat._type)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*cat._brain);
}

Cat& Cat::operator= (const Cat& cat)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &cat)
		return *this;
	_type = cat._type;
	*_brain = *cat._brain;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << _type << " says meow" << std::endl;
}