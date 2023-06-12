/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:42:17 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/12 19:28:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_RPN_HPP
# define CLASS_RPN_HPP

#define COLOR_RED "\x1b[31m"
#define RESET "\x1b[0m"

#include <iostream>
#include <stack>

class RPN {

    private:
        std::string _expression;

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