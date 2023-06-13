/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:46:11 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/13 18:55:02 by jmabel           ###   ########.fr       */
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

void RPN::calculation()
{ 
    bool	isOperatorFlag = false;

	for (size_t i = 0; i < _expression.size(); i++)
    {
		char token = _expression[i];

		if (token == ' ' || token == '\t')
			continue ;

		if (!isOperator(token)) {
			if (isdigit(token)){
				isOperatorFlag = false;
				double number = (token - '0');
				_operandStack.push(number);
			} else {
				throw RPNException("Error");
			}
		} else {
			if (_operandStack.size() < 2) {
				throw RPNException("Error");
			}
			
			isOperatorFlag = true ;
	
			double operand2 = _operandStack.top();
			_operandStack.pop();
			
			double operand1 = _operandStack.top();
			_operandStack.pop();
		
			if (token == '+')
				_operandStack.push(operand1 + operand2);
			else if (token == '-')
				_operandStack.push(operand1 - operand2);
			else if (token == '*')
				_operandStack.push(operand1 * operand2);
			else if (token == '/')
				_operandStack.push(operand1 / operand2);
		}
    }
	if (isOperatorFlag == false)
		throw RPNException("Error");
	
	std::cout << _operandStack.top() << std::endl;
}

bool	RPN::isOperator(char token) {
	if (token == '+' || token == '-' || token == '/' || token == '*')
		return true;
	return false;
}
