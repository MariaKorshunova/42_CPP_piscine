/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:47:25 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/27 15:14:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Warlock
{
private:
	std::string	name;
	std::string title;

public:
	Warlock(std::string name, std::string title)
	{
		this->name = name;
		this->title = title;
		std::cout << name << ": This looks like another boring day.\n";
	};
	
	~Warlock()
	{
		std::cout << name << ": My job here is done!\n";
	}

	std::string	getName() const { return name; }
	std::string getTitle() const { return title; }

	void	setTitle(std::string title) { this->title = title; }
	
	void	introduce() const
	{
		std::cout << name << ": I am " << name << ", " << title << "!\n"; 
	}
};
