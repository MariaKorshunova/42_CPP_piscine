/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:54:52 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/12 17:44:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& inputFile){
	_inputFile = inputFile;
	_fillDatabase();
	if (_data.empty())
			throw(BitcoinExchangeException("btc: Error: " DATABASE " empty"));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btcCopy)
{
	if (this == &btcCopy)
		return *this;
	return *this;
}


BitcoinExchange::~BitcoinExchange(){
};

void BitcoinExchange::_fillDatabase(){

	std::ifstream	infile(DATABASE);
	if(!infile.is_open()) {
		throw(BitcoinExchangeException("btc: Error: " DATABASE " can't be open"));
	}
	std::string	line = "";
	std::string date = "";
	size_t pos;
	getline(infile, line);
	while (getline(infile, line))
	{
		pos = line.find(',');
		if (pos == std::string::npos){
			throw (BitcoinExchangeException("btc: Error: uncorrect row in database"));
		}
		std::string dateString = line.substr(0, pos);
		_trimString(dateString);
		if (_replaceDashCheckDigits(dateString) == false) {
			throw (BitcoinExchangeException("btc: Error: uncorrect date in database"));
		}
		Date date = _parseDate(dateString);
		if (checkDate(date.getYear(), date.getMonth(), date.getDay()) == false) {
			throw (BitcoinExchangeException("btc: Error: uncorrect date in database"));
		}

		std::string exchangeRateString = line.substr(pos + 1);
		double exchangeRate = 0;
		char* endPtr;
		exchangeRate = std::strtod(exchangeRateString.c_str(), &endPtr);
		if (endPtr != exchangeRateString.c_str() + exchangeRateString.length()){
			throw (BitcoinExchangeException("btc: Error: uncorrect exchange_rate in database"));
		}
		_data.insert(std::pair<Date, double>(date, exchangeRate));
	}
	infile.close();
}

Date	BitcoinExchange::_parseDate(std::string& dateString)
{	
	std::stringstream ss;
	int year, month, day;
	
	ss << dateString;
	ss >> year >> month >> day;
	return Date(year, month, day);
}

bool	BitcoinExchange::_checkHeaderInputFile(std::string& line)
{
	_eraseSpacesAndTabs(line);
	if (line != "date|value")
		return false;
	return true;
}

bool	BitcoinExchange::_replaceDashCheckDigits(std::string& str)
{
	int numberDash = 0;
	
	if (str[0] == '-' || str[str.length() - 1] == '-')
		return false;
	for (size_t i = 0; i < str.length(); i++){
		if (str[i] == '-')
		{
			if (str[i + 1] == '-')
				return false;
			numberDash++;
			str[i] = ' ';
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	if (numberDash != 2)
		return false;
	return true;
}

void	BitcoinExchange::_eraseSpacesAndTabs(std::string& line)
{
    size_t pos = 0;

    while ((pos = line.find_first_of(" \t", pos)) != std::string::npos) {
        line.erase(pos, 1);
    }
}

void	BitcoinExchange::_trimString(std::string& str)
{
	size_t start = str.find_first_not_of(" \t");
	if (start != std::string::npos) {
		str = str.substr(start);
	} else {
		str.clear();
		return ;
	}

	size_t end = str.find_last_not_of(" \t");
	if (end != std::string::npos) {
		str = str.substr(0, end + 1);
	}
}

bool	BitcoinExchange::_checkValue(double value)
{
	if (value < 0){
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	
	if (value > 1000){
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}


double	BitcoinExchange::_findCLosestDay(Date& date)
{	
	int minDiffDays = INT_MAX;
	int diffDays = 0;
	double value = -1;
	std::map<Date, double>::iterator it;
	for  (it = _data.begin(); it != _data.end(); it++)
	{
		diffDays = date.differenceInDays(it->first);
		if (diffDays >= 0 && diffDays < minDiffDays)
		{
			value = it->second;
			minDiffDays = diffDays;
		}
	}
	return value;
}

void BitcoinExchange::exchange()
{
	std::ifstream	input(_inputFile);
	size_t			pos;
	double			exchange;
	
	if(!input.is_open()) {
		throw(BitcoinExchangeException("btc: Error: input file can't be open"));
	}
	std::string line = "";
	getline(input, line);
	if (_checkHeaderInputFile(line) == false) {
		throw(BitcoinExchangeException("btc: Error: header of input file should be like 'date|value' "));
	}
	while (getline(input, line))
	{
		std::string dateValue = line;
		pos = dateValue.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		
		std::string dateString = dateValue.substr(0, pos);
		_trimString(dateString);
		if (_replaceDashCheckDigits(dateString) == false) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		Date date = _parseDate(dateString);
		if (checkDate(date.getYear(), date.getMonth(), date.getDay()) == false) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		std::string valueString = line.substr(pos + 1);
		_trimString(valueString);
		if (valueString.empty()){
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		double value = 0;
		char* endPtr;
		value = std::strtod(valueString.c_str(), &endPtr);
		if (endPtr != valueString.c_str() + valueString.length()){
			std::cerr << "Error: not a number." << std::endl;
			continue ;
		}
		if (_checkValue(value) == false)
			continue;
		if (_data.find(date) == _data.end())
			exchange = _findCLosestDay(date);
		else
			exchange = _data[date];
		if (exchange == -1){
			std::cerr << "Error: date is earlier than the earliest date in database  => " << date << std::endl;
			continue ;
		}
		std::cout << date << " => " << value  << " = " << exchange * value << std::endl; 		
	}
	input.close();
}
