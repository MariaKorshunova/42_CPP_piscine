/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:42:17 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/13 18:56:07 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_RPN_HPP
# define CLASS_RPN_HPP

#include <iostream>
#include <stack>

class RPN {

    private:
        std::string 		_expression;
        std::stack<double>	_operandStack;

        bool	isOperator(char token);

    public:
        RPN(std::string expression);
        RPN(const RPN& copy);
        RPN& operator=(const RPN& copy);
        ~RPN();

        const std::string&  getExpression() const;

        void calculation();

    class RPNException: public std::exception {
	    private:
		    const char*	_promptMessage;
	
	    public:
		    RPNException(const char* message): _promptMessage(message){}

		    virtual const char* what() const throw() {
			return(_promptMessage);
		}
	};

};

#endif //CLASS_RPN_HPP