/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:53:14 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/28 15:52:04 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		// here is compilation erorr
		// variable type 'Animal' is an abstract class
	
		// Animal	animal;
		// Animal* pAnimal;
		// pAnimal = new Animal();
	}
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		j->makeSound();
		i->makeSound();
		
		Animal* animals[6];
		for (int i = 0; i < 3; i++)
			animals[i] = new Dog();
		for (int i = 3; i < 6; i++)
			animals[i] = new Cat();

		for (int i = 0; i < 6; i++)
			delete animals[i];

		delete j;
		delete i;
	}
	return 0;
}