/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:13:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/30 21:27:08 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_AMATERIA_HPP
#define CLASS_AMATERIA_HPP

#include <iostream>

#include "MateriaSource.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _materiaType;

public:
	AMateria(std::string const & type);
	AMateria(const AMateria& materia);
	AMateria& operator= (const AMateria& materia);
	virtual ~AMateria();
	
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif // CLASS_AMATERIA_HPP