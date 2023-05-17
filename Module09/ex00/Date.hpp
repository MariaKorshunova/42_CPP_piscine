/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:29:32 by jmabel            #+#    #+#             */
/*   Updated: 2023/05/15 19:00:46 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_DATE_HPP
#define CLASS_DATE_HPP

#include <iostream>

class	Date {

	private:
		int	_year;
		int	_month;
		int	_day;

	public:

		Date(int year, int month, int day);
		Date(const Date& copy);
		Date& operator=(const Date& copy);
		~Date();


		int getYear() const;
		int getMonth() const;
		int getDay() const;

		bool operator< (const Date& other) const;
		bool operator> (const Date& other) const;
		bool operator= (const Date& other) const;

};

std::ostream& operator<< (std::ostream& out, const Date& date);

bool checkDate(int year, int month, int day);

#endif //CLASS_DATE_HPP