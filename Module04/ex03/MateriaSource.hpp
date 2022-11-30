/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:10:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/30 19:37:04 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_MATERIASOURCE_HPP
#define CLASS_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class	MateriaSource: public IMateriaSource
{
private:
    AMateria*	_store[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource& source);
    MateriaSource& operator= (const MateriaSource& source);
    virtual ~MateriaSource();
    
    virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};

#endif // CLASS_MATERIASOURCE_HPP