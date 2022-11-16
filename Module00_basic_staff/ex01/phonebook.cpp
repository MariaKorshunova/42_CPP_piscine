/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:44:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/16 18:05:39 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	PhoneBook::readValue(std::string promptMessage)
{
	std::string	value;

	do
	{
		std::cout << promptMessage;
		std::getline(std::cin, value);
		if (std::cin.eof())
			exit(1);
		if (value.empty())
			std::cout << "Can't be empty. Please, try again" << std::endl;
	}	while (value.empty());
	
	return value;
}

void	PhoneBook::addContact()
{
	std::string	value;
	
	value = readValue("First name: ");
}

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

int	main(void)
{
	PhoneBook	pBook;
	std::string	cmd;

	std::cout << "Enter a command(ADD, SEARCH, EXIT): " << std::endl;
	std::getline(std::cin, cmd);
	while (!std::cin.eof())
	{
		if (cmd == "ADD")
			pBook.addContact(); 
		std::cout << "Enter a command(ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, cmd);
	}
	return 0;
}
