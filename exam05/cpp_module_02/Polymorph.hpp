/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:47:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/28 15:13:07 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

class Polymorph: public ASpell
{
public:
  Polymorph(): ASpell("Polymorph", "turned into a critter") {}
  ~Polymorph() {}

  virtual ASpell* clone() const { return new Polymorph(); }
};