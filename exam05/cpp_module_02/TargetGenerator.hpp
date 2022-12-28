/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:03:42 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/28 15:07:57 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
private:
    std::map<std::string, ATarget* >map;

public:
    TargetGenerator() {};
    ~TargetGenerator() {};

    void learnTargetType(ATarget* target) { map[target->getType()] = target; }
    void forgetTargetType(std::string target) { map.erase(target); }
    
    ATarget* createTarget(std::string target)
    {
        if (map[target])
            return map[target];
        return 0;
    }
};