/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:53:14 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 20:44:25 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// delete j; //should not create a leak
	// delete i;

	// Animal* animals[6];
	// for (int i = 0; i < 3; i++)
	// 	animals[i] = new Dog();
	// for (int i = 3; i < 6; i++)
	// 	animals[i] = new Cat();

	// for (int i = 0; i < 6; i++)
	// 	delete animals[i];

	Dog dog;
	{
		Dog tmp = dog;
	}
	
	return 0;
}