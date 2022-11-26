/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 20:01:55 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_DOG_HPP
#define CLASS_DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain* _brain;

public:
	Dog(const std::string& type = "Dog");
	Dog(const Dog& dog);
	Dog& operator= (const Dog& dog);
	virtual ~Dog();
	
	virtual void	makeSound() const;
};


#endif // CLASS_DOG_HPP