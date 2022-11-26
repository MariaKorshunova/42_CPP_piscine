/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:16:10 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 18:01:33 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(const std::string& type): WrongAnimal(type)
{
	std::cout << "Default WrongCat constructor called"<< std::endl;
}

WrongCat::WrongCat(const WrongCat& cat): WrongAnimal(cat._type)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat& cat)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this == &cat)
		return *this;
	_type = cat._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << _type << " says meow" << std::endl;
}