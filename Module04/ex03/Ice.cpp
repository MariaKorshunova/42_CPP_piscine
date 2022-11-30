/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:21:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/30 21:20:17 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::Ice(const Ice& ice): AMateria(ice._materiaType)
{
}

Ice& Ice::operator= (const Ice& ice)
{
	if (this == &ice)
		return *this;
	AMateria::operator= (ice);
	return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target)
{
	std:: cout << "* shoots an ice bolt at ";
	AMateria::use(target);
	std::cout << " *" << std::endl;
					
}
