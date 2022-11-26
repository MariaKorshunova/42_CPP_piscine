/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 17:38:13 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_WRONGANIMAL_HPP
#define CLASS_WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string	_type;

public:
	WrongAnimal(const std::string& type = "WrongAnimal");
	WrongAnimal(const WrongAnimal& animal);
	WrongAnimal& operator= (const WrongAnimal& animal);
	virtual ~WrongAnimal();

	const std::string&	getType() const;

	void	setType(std::string& type);
	
	void	makeSound() const;
};


#endif // CLASS_WRONGANIMAL_HPP