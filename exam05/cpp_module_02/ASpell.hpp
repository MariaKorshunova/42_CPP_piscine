/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:12:17 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/27 16:03:04 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
    std::string name;
    std::string effects;

public:
    ASpell(std::string name, std::string effects)
    {
        this->name = name;
        this->effects = effects;
    }

    virtual ~ASpell() { }

    std::string getName() const { return name; }
    std::string getEffects() const { return effects; }
    
    void launch(ATarget& target);
     
    virtual ASpell* clone() const = 0;
};

