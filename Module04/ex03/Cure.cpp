/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:21:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/30 21:20:13 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::Cure(const Cure& cure): AMateria(cure._materiaType)
{
}

Cure& Cure::operator= (const Cure& cure)
{
	if (this == &cure)
		return *this;
	AMateria::operator= (cure);
	return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& target)
{
	std:: cout << "* heals ";
	AMateria::use(target);
	std::cout << "’s wounds *" << std::endl;
					
}
