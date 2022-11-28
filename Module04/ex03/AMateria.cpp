/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:46:26 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/28 16:51:21 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type):_materiaType(type)
{
}

AMateria::AMateria(const AMateria& materia)
{
	_materiaType = materia._materiaType;
}

AMateria& AMateria::operator= (const AMateria& materia)
{
	if (this == &materia)
		return *this;
	_materiaType  = materia._materiaType;
	return *this;
}

std::string const & AMateria::getType() const { return _materiaType; }
