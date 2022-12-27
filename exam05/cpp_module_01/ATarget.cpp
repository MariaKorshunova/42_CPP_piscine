/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:28:41 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/27 15:30:20 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

void ATarget::getHitBySpell(ASpell &spell)
{
    std::cout << type << " has been " << spell.getEffects() << "!\n";
}