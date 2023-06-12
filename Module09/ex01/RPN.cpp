/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:46:11 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/12 19:44:09 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expression)
{
    if (expression.size() == 0)
        throw(RPNException("RPN: Error: empty string"));
    _expression = expression;
}

RPN::RPN(const RPN& copy): _expression(copy.getExpression())
{
    *this = copy;
}

RPN& RPN::operator=(const RPN& copy)
{
    if (this == &copy)
        return *this;
    _expression = copy.getExpression();
    return *this;
}

RPN::~RPN(){}

const std::string&  RPN::getExpression() const { return _expression; }

void RPN::calculation();
{

}