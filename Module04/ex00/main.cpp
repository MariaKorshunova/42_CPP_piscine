/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:53:14 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 18:12:41 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main ( void )
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << "Type of animal meta: " << meta->getType() << " " << std::endl;
		std::cout << "Type of dog j: " << j->getType() << " " << std::endl;
		std::cout << "Type of cat i: " << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		const WrongCat* cat = new WrongCat();
		
		std::cout << "Type of wronganimal meta: " << meta->getType() << " " << std::endl;
		std::cout << "Type of wrongcat i: " << i->getType() << " " << std::endl;
		std::cout << "Type of wrongcat cat: " << cat->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		cat->makeSound();
		
		delete meta;
		delete i;
		delete cat;
	}
	
	return 0;
}