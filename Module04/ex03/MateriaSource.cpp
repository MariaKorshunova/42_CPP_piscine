/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:18:01 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/30 21:45:17 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_store[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& source)
{
	for (int i = 0; i < 4; i++)
		_store[i] = source._store[i]->clone();
}

MateriaSource& MateriaSource::operator= (const MateriaSource& source)
{
	if (this == &source)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (_store[i])
			delete _store[i];
	}
	for (int i = 0; i < 4; i++)
		_store[i] = source._store[i]->clone();
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_store[i])
			delete _store[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	int freeSlot = -1;
	for (int i = 0; i < 4; i++)
	{
		if (_store[i])
		{
			if (_store[i]->getType() == materia->getType())
			{
				std::cout 	<< "Materia " << materia->getType()
							<< " is already in memory" << std::endl;
				return ;
			}
		}
		else
			freeSlot = i;
	}
	if (freeSlot == -1)
	{
		std::cout << "Not empty memory for materia" << std:: endl;
		return ;
	}
	std::cout << "Learn materia: " << materia->getType() << std::endl;
	_store[freeSlot] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_store[i])
		{
			if (_store[i]->getType() == type)
			{
				std::cout << "Create materia: " << type << std::endl;
				return _store[i]->clone();
			}
		}
	}
	std::cout << "Unknown materia: " << type << std::endl;
	return 0;
}	
