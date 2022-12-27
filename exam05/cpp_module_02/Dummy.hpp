/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:40:13 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/27 15:42:20 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

class Dummy: public ATarget
{
public:
    Dummy(): ATarget("Target Practice Dummy") {};
    ~Dummy () {};

    virtual ATarget* clone() const { return new Dummy(); }
};