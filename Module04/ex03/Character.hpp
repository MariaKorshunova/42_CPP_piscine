/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:53:25 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/30 21:00:36 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CHARACTER_HPP
#define CLASS_CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Character: public ICharacter
{
private:
	std::string 	_name;
	AMateria*		_inventory[4];
	AMateria**		_floor;
	int				_floorCount;

public:
	Character(std::string name);
	Character(const Character& character);
	Character& operator= (const Character& character);
	virtual ~Character();
	
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif // CLASS_CHARACTER_HPP