/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:17:11 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/07 20:52:14 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter()
{
}

Converter::Converter(const Converter& converter)
{
	(void) converter;
}

Converter& Converter::operator= (const Converter& converter)
{
	(void) converter;
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
	while (value[i])
	{
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
	if (isDot == false)
		return INT;
	if (isFloat == true)
		return FLOAT;
	return DOUBLE;
}

// void	Converter::convertToString()
// {
// 	std::cout << "char:  impossible\n" <<
// 				 "int: impossible\n" <<
// 				 "float: impossible\n" <<
//  				 "double: impossible" << std::endl; 	
// }

// void	Converter::convertToChar(char value)
// {
// 	std::cout << "char: " 	<< 	value << "\n";
	
// 	std::cout << "int: " 	<< 	static_cast<int>(value) << "\n";

// 	std::cout << "float: " 	<< 	std::fixed << std::setprecision(1) << 
// 								static_cast<float>(value) << "f" << "\n";
							
// 	std::cout << "double: " << 	std::fixed << std::setprecision(1) <<
// 								static_cast<double>(value) <<
// 								std::endl; 
// }

// void	Converter::convertToInt(std::string& value)
// {
// 	try
// 	{
// 		int intValue = std::stoi(value);
// 		char c = static_cast<char>(intValue);
// 		if (isprint(c))
// 			std::cout << "char: " <<  c << "\n";
// 		else
// 			std::cout << "char: Non displayable\n";
// 		std::cout << "int: " 	<< 	value << "\n";
// 	}
// 	catch (std::out_of_range &e)
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 	}
// 	catch(std::invalid_argument &e)
// 	{
// 		std::cout << "impossible in" << std::endl;
// 	}

// }

// convertToChar(static_cast<char>(*value.c_str()));

// void	Converter::convertToChar(std::string& value)
// {
// 	std::cout << "char: ";
// 	if (_type == STRING)
// 		std::cout << "impossible";
// 	else if (_type == CHAR)
// 		char c = static_cast<char>(*value.c_str());
// 		std::cout << c;
// 	case INT:
// 		try
// 		{ 
// 			int intValue = std::stoi(value);
// 			char c = static_cast<char>(intValue);
// 			std::cout << c; 
// 		}
// 		catch (std::out_of_range &e) { std::cout << "impossible"; }
// 		break ;
	
// 	default :
// 		break;
// 	}
// 	std::cout << std::endl;
// }

void	Converter::convert(std::string& value)
{
	_type = defineType(value);
	convertToChar(value);
}


// https://github.com/Renat-M/CPP_Piscine/blob/main/cpp_day06/ex00/src/Convert.cpp
