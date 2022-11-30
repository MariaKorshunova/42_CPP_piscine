/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:54:30 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/01 02:18:20 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	
	std::cout << 	"\n-----------------Test 1-----------------\n" <<
					"Create Materia source, create unknown materia, learn materia\n" <<
					std::endl;
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp;
	tmp = src->createMateria("ice");
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Ice* doubleIce = new Ice();
	src->learnMateria(doubleIce);
	delete doubleIce;

	std::cout << 	"\n-----------------Test 2-----------------\n" <<
					"Create Characters, materia and equip\n" <<
					std::endl;	
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << 	"\n-----------------Test 3-----------------\n" <<
				"Use materia. Check it with subject\n" <<
				std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << 	"\n-----------------Test 4-----------------\n" <<
				"Unequip to floor\n" <<
				std::endl;	
	me->unequip(0);
	me->use(0, *bob);
	me->unequip(3);

	delete bob;
	delete me;
	delete src;
return 0;
}
