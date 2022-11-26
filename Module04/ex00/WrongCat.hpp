/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 17:51:26 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_WRONGCAT_HPP
#define CLASS_WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat(const std::string& type = "WrongCat");
	WrongCat(const WrongCat& cat);
	WrongCat& operator= (const WrongCat& cat);
	virtual ~WrongCat();

	void	makeSound() const;
};


#endif // CLASS_WRONGCAT_HPP