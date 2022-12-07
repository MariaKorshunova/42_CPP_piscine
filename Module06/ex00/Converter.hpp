/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:09:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/07 20:29:24 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONVERTER_HPP
#define CLASS_CONVERTER_HPP

#include <iostream>
#include <iomanip>

class Converter
{
private:
	enum Type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		STRING
	};
	
	Type	_type;
	Type	defineType(std::string& value);

	// void	convertToString();
	void	convertToChar(std::string& value);
	// void	convertToInt(std::string& value);

public:

	Converter();
	Converter(const Converter& converter);
	Converter& operator= (const Converter& converter);
	~Converter();

	void	convert(std::string& value);

};

#endif // CLASS_CONVERTER_HPP