/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:20:47 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/27 15:58:54 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
private:
    std::string type;

public:
    ATarget(std::string type)
    {
        this->type = type;
    }

    virtual ~ATarget(){}

    std::string getType() const { return type; }

    void getHitBySpell(ASpell &spell);
    
    virtual ATarget* clone() const = 0;
};