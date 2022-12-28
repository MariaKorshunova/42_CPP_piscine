/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:47:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/28 15:13:16 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

class Fireball: public ASpell
{
public:
  Fireball(): ASpell("Fireball", "burnt to a crisp") {}
  ~Fireball() {}

  virtual ASpell* clone() const { return new Fireball(); }
};