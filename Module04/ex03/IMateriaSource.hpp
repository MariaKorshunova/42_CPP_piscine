/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:04:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/30 20:58:54 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_IMATERIASOURCE_HPP
#define CLASS_IMATERIASOURCE_HPP

#include"AMateria.hpp"

class AMateria;

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif // CLASS_IMATERIASOURCE_HPP