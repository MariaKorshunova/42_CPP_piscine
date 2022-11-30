/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:46:41 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/30 21:28:01 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ICHARACTER_HPP
#define CLASS_ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif // CLASS_ICHARACTER_HPP