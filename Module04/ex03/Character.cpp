/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:37:47 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/01 02:18:51 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name):
				_name(name),
				_floorCount(0)
{
	std::cout << "New character: " << name << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character& character):
				_name(character._name),
				_floorCount(character._floorCount)
{
	for (int i = 0; i < 4; i++)
	{
		if (character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	for (int i = 0; i < character._floorCount; i++)
		_floor[i] = character._floor[i]->clone();
}

Character& Character::operator= (const Character& character)
{
	if (this == &character)
		return *this;
	_name = character._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	for(int i = 0; i < _floorCount; i++)
		delete _floor[i];
	for (int i = 0; i < character._floorCount; i++)
		_floor[i] = character._floor[i]->clone();
	_floorCount = character._floorCount;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	for(int i = 0; i < _floorCount; i++)
		delete _floor[i];
	delete [] _floor;
}

std::string const & Character::getName() const { return _name; }

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _name << " equip with " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout 	<< _name << "can't equip " << m->getType() <<
				". Equipment is full." << std::endl;
}

void Character::unequip(int idx)
{
	if ((idx < 0 || idx > 4) || !_inventory[idx])
	{
		std::cout << _name << ": empty equipment slot. Can't unequip" << std::endl;
		return ;	
	}
	AMateria**	tmp = new AMateria*[_floorCount + 1];
	for (int i = 0; i < _floorCount; i++)
		tmp[i] = _floor[i];
	tmp[_floorCount] = _inventory[idx];
	delete [] _floor;
	_floor = tmp;
	_inventory[idx] = 0;
	std::cout << _floor[_floorCount]->getType() << " unequip on floor" << std::endl;
	_floorCount++;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4)
		return ;
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << _name << ": empty equipment slot. Can't use" << std::endl;
}