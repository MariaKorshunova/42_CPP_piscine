/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:52:52 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/28 23:35:53 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CURE_HPP
#define CLASS_CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure& cure);
	Cure& operator= (const Cure& cure);
	~Cure();	
	
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif // CLASS_CURE_HPP