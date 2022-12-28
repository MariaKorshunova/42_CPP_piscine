/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:40:13 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/28 14:05:39 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

class BrickWall: public ATarget
{
public:
    BrickWall(): ATarget("Inconspicuous Red-brick Wall") {};
    ~BrickWall () {};

    virtual ATarget* clone() const { return new BrickWall(); }
};