/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:36:18 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/27 15:42:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class Fwoosh: public ASpell
{
public:
    Fwoosh(): ASpell("Fwoosh", "fwooshed") {};
    ~Fwoosh() {};
    
    virtual ASpell* clone() const { return new Fwoosh(); }
};