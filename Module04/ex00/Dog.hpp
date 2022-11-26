/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 17:34:59 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_DOG_HPP
#define CLASS_DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog(const std::string& type = "Dog");
	Dog(const Dog& dog);
	Dog& operator= (const Dog& dog);
	virtual ~Dog();
	
	virtual void	makeSound() const;
};


#endif // CLASS_DOG_HPP