/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:17:11 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/08 12:47:49 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter()
{
}

Converter::Converter(const Converter& converter)
{
	_type = converter._type;
	_precision = converter._precision;
}

Converter& Converter::operator= (const Converter& converter)
{
	if (this == &converter)
		return *this;
	_type = converter._type;
	_precision = converter._precision;
	return *this;
}

Converter::~Converter()
{
}

Converter::Type	Converter::defineType(std::string& value)
{
	if (value.length() == 1 && !isdigit(value[0]))
		return CHAR;
	int i = (value[0] == '+' || value[0] == '-') ? 1 : 0;
	bool isDot = false;
	bool isFloat = false;
	int	precision = 0;
	while (value[i])
	{
		precision += isDot;
		if (value[i] == '.')
		{
			if (isDot == true)
				return STRING;
			isDot = true;
		}
		else if (value[i] == 'f' && !value[i + 1])
			isFloat = true;
		else if (!isdigit(value[i]))
			return STRING;
		i++;
	}
	precision == 0 ? _precision = 1 : _precision = precision;
	if (isDot == false)
		return INT;
	if (isFloat == true)
	{
		_precision--;
		return FLOAT;
	}
	return DOUBLE;
}

void	Converter::convertFromString()
{
	std::cout << "char:  impossible\n" <<
				 "int: impossible\n" <<
				 "float: impossible\n" <<
 				 "double: impossible" << std::endl; 	
}

void	Converter::convertFromPseudoLiteral(std::string& value)
{
	try
	{
	double number = std::stod(value);
	std::cout << "char:  impossible\n" <<
				 "int: impossible\n" <<
				 "float: " << static_cast<float>(number) << "f" << std::endl <<
 				 "double: " << number << std::endl;
	}
	catch(std::out_of_range& e) { convertFromString(); }
	catch(std::invalid_argument& e) { convertFromString(); }
}

void	Converter::convertFromChar(std::string& value)
{
	char c = value[0];
	std::cout << "char: " 	<< 	c << "\n";
	
	std::cout << "int: " 	<< 	static_cast<int>(c) << "\n";

	std::cout << "float: " 	<< 	std::fixed << std::setprecision(1) << 
								static_cast<float>(c) << "f" << "\n";
							
	std::cout << "double: " << 	std::fixed << std::setprecision(1) <<
								static_cast<double>(c) <<
								std::endl; 
}

void	Converter::convertNumberToChar(std::string& value)
{
	try
	{
		int number = std::stoi(value);
		char c = static_cast<char>(number);
		if (number < 0 || number > 127)
			std::cout << "char: impossible" << std::endl;
		else if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch(std::out_of_range& e){ std::cout << "char: impossible" << std::endl; }
	catch(std::invalid_argument& e) { std::cout << "char: impossible" << std::endl; }
}

void	Converter::convertNumberToInt(std::string& value)
{
	try
	{
		int number = std::stoi(value);
		std::cout << "int: " << number << std::endl;
	}
	catch(std::out_of_range& e){ std::cout << "int: impossible" << std::endl; }
	catch(std::invalid_argument& e) { std::cout << "int: impossible" << std::endl; }	
}

void	Converter::convertNumberToFloat(std::string& value)
{
	try
	{
		float number = std::stof(value);
		std::cout << "float: " 	<< 	std::fixed << std::setprecision(_precision) <<
							number << "f" << std::endl;		
	}
	catch(std::out_of_range& e){ std::cout << "float: impossible" << std::endl; }
	catch(std::invalid_argument& e) { std::cout << "float: impossible" << std::endl; }	
}

void	Converter::convertNumberToDouble(std::string& value)
{
	try
	{
		double number = std::stof(value);
		std::cout << "double: " << 	std::fixed << std::setprecision(_precision) <<
							number << std::endl;	
	}
	catch(std::out_of_range& e){ std::cout << "double: impossible" << std::endl; }
	catch(std::invalid_argument& e) { std::cout << "double: impossible" << std::endl; }	
}

void	Converter::convert(std::string& value)
{
	_type = defineType(value);
	switch (_type)
	{
	case STRING:
		if (value == "-inf" || value == "+inf" || value == "nan" ||
			value == "-inff" || value == "+inff" || value == "nanf" )
			convertFromPseudoLiteral(value);
		else
			convertFromString();
		break ;
	case CHAR:
		convertFromChar(value);
		break ;
	default:
		convertNumberToChar(value);
		convertNumberToInt(value);
		convertNumberToFloat(value);
		convertNumberToDouble(value);
		break ;
	}
}
