/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:32:30 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/12 17:52:12 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;
}

Date::Date(const Date& copy)
{
    *this = copy;
}

Date& Date::operator=(const Date& copy)
{
    if (this == &copy)
        return *this;
    this->_year = copy.getYear();
    this->_month = copy.getMonth();
    this->_day = copy.getDay();
    return *this;
}

Date::~Date() { }

int Date::getYear() const { return _year; }
int Date::getMonth() const { return _month; }
int Date::getDay() const { return _day; }

int Date::differenceInDays(const Date& other)
{
	int thisDays = _year * 365 + _month * 30 + _day;
	int	otherDays = other.getYear() * 365 + other.getMonth() * 30 + other.getDay();

	return (thisDays - otherDays);

}

bool Date::operator< (const Date& other) const
{
	if (this->_year < other.getYear())
		return true;
	if (this->_year == other.getYear())
	{
		if (this->_month < other.getMonth())
			return true;
		if (this->_month == other.getMonth() && this->_day < other.getDay())
			return true;
	}
	return false;
}

bool Date::operator> (const Date& other) const
{
	if (this->_year > other.getYear())
		return true;
	if (this->_year == other.getYear())
	{
		if (this->_month > other.getMonth())
			return true;
		if (this->_month == other.getMonth() && this->_day > other.getDay())
			return true;
	}
	return false;
}

bool Date::operator= (const Date& other) const
{
	if (this->_year == other.getYear() && this->_month == other.getMonth()
			&& this->_day == other.getDay())
			return true;
	return false;
}


std::ostream& operator<< (std::ostream& out, const Date& date)
{
	
	out << date.getYear() << '-' 
		<< std::setw(2) << std::setfill('0') << date.getMonth() << '-'
		<< std::setw(2) << std::setfill('0') << date.getDay();
	return out;
}


bool checkDate(int year, int month, int day)
{
	bool flagLeapYear;
	if (year % 400 == 0)
		flagLeapYear = true;
	else if (year % 100 == 0)
		flagLeapYear = false;
	else if (year % 4 == 0)
		flagLeapYear = true;
	else
		flagLeapYear = false;

	bool flagRightDay = true;
	if ((month == 4 || month == 6 || month == 9 || month == 11) &&
			(day <= 0 || day > 30))
			flagRightDay = false;
	else if (month == 2)
	{
		if (flagLeapYear == false && (day <= 0 || day > 28))
			flagRightDay = false;
		else if (flagLeapYear == true && (day <= 0 || day > 29))
			flagRightDay = false;
	}
	else if (day <=0 || day > 31)
		flagRightDay = false;
	
	if (year < 0 || month <= 0 || month > 12 || flagRightDay == false)
		return false;
	
	return true; 	
}