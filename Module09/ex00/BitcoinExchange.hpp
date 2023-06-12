/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:42:20 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/12 17:26:28 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BITCOINEXCHANGE_HPP
#define CLASS_BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream> // for open file
#include <sstream> // for stringstream
#include <map>
#include <limits.h>
#include "Date.hpp"

#define DATABASE "data.csv"
#define DATABASE_delimeter ','

#define COLOR_RED "\x1b[31m"
#define RESET "\x1b[0m"


class BitcoinExchange {

private:
	std::string _inputFile;
	std::map<Date, double> _data;

	void 	_fillDatabase();
	Date	_parseDate(std::string& dateString);

	bool	_checkHeaderInputFile(std::string& line);
	bool	_replaceDashCheckDigits(std::string& str);
	void	_eraseSpacesAndTabs(std::string& line);
	void	_trimString(std::string& str);

	bool	_checkValue(double value);

	double	_findCLosestDay(Date& date);

public:
	BitcoinExchange(const std::string& inputFile);
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator= (const BitcoinExchange& copy);
	~BitcoinExchange();

	void exchange();

class BitcoinExchangeException: public std::exception {
	private:
		const char*	_promptMessage;
	
	public:
		BitcoinExchangeException(const char* message): _promptMessage(message){}

		virtual const char* what() const throw() {
			return(_promptMessage);
		}
	};

};

#endif // CLASS_BITCOINEXCHANGE_HPP