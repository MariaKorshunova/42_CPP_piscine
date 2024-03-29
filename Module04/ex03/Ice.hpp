/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:52:52 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/30 21:16:22 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ICE_HPP
#define CLASS_ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice& ice);
	Ice& operator= (const Ice& ice);
	~Ice();	
	
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif // CLASS_ICE_HPP