/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:54:06 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/28 14:59:11 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
private:
    std::map<std::string, ASpell* > map;

public:
    SpellBook() {};
    ~SpellBook() {};

    void learnSpell(ASpell* spell) { map[spell->getName()] = spell; }
    void forgetSpell(std::string spell){ map.erase(spell); }

    ASpell* createSpell(std::string spell)
    {
        if (map[spell])
            return map[spell];
        return 0;
    }
};
