/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 17:34:50 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CAT_HPP
#define CLASS_CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat(const std::string& type = "Cat");
	Cat(const Cat& cat);
	Cat& operator= (const Cat& cat);
	virtual ~Cat();

	virtual void	makeSound() const;
};


#endif // CLASS_CAT_HPP