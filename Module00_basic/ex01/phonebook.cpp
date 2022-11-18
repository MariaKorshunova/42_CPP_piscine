/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:44:59 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/18 16:28:14 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(): m_nextIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

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

void	PhoneBook::printContacts()
{
	int sizebook;
	
	if (m_nextIndex < 8)
		sizebook = m_nextIndex;
	else
		sizebook = 8;
	std::cout << "|index     |first name|last name |nickname  |";
	for (int i = 0; i < sizebook; i++)
	{
		std::cout << "\n|----------|----------|----------|----------|\n|" <<
				i + 1 << "         |";
		print10(m_contacts[i].GetFirstName());
		print10(m_contacts[i].GetLastName());
		print10(m_contacts[i].GetNickName());	
	}
	std::cout << "\n" << std::endl;
}

void	PhoneBook::printOneContact(int i)
{
	std::cout << "First name: " << m_contacts[i % 8].GetFirstName() <<
			"\nLast name: " << m_contacts[i % 8].GetLastName() <<
			"\nNick name: " << m_contacts[i % 8].GetNickName() <<
			"\nPhone number: " << m_contacts[i % 8].GetPhoneNumber() <<
			"\nDarkest secret: " << m_contacts[i % 8].GetDarkestSecret() <<
			"\n" << std::endl;
}

void	PhoneBook::print10(std::string str)
{
	int	len = static_cast<int>(str.length());
	
	if (len < 10)
	{
		std::cout << str;
		for (int i = 0; i < 10 - len; i++)
			std::cout << " ";
	}
	else
		std::cout << str.substr(0, 9) << ".";
	std::cout << "|";
}

void	PhoneBook::addContact()
{
	std::string	value;

	value = readValue("First name: ");
	m_contacts[m_nextIndex % 8].SetFirstName(value);
	value = readValue("Last name: ");
	m_contacts[m_nextIndex % 8].SetLastName(value);
	value = readValue("Nick name: ");
	m_contacts[m_nextIndex % 8].SetNickName(value);
	value = readValue("Phone number: ");
	m_contacts[m_nextIndex % 8].SetPhoneNumber(value);
	value = readValue("Darkest secret: ");
	m_contacts[m_nextIndex % 8].SetDarkestSecret(value);
	m_nextIndex++;
	std::cout << std::endl;
}

void	PhoneBook::searchContact()
{
	std::string	str;
	int i = 0;
	
	printContacts();
	std::cout << "Enter the index of the contact: ";
	std::cin >> str;
	if (std::cin.eof())
		exit (1);
	std::cin.ignore(32767, '\n');
	if (str.length() == 1 && std::isdigit(str[0]))
		i = std::stoi(str);
	if (i > 0 && i < 9 && i <= m_nextIndex)
		printOneContact(i - 1);
	else
		std::cout << "Invalid index of the contact\n" << std::endl;
}

int	main(void)
{
	PhoneBook	pBook;
	std::string	cmd;

	do
	{
		std::cout << "Enter a command(ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break ;
		else if (cmd == "ADD")
			pBook.addContact();
		else if (cmd == "SEARCH")
			// std::cout << "Test\n" << std::endl;
			pBook.searchContact();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Command does not exist." << std::endl;
	} while (!std::cin.eof());
	return 0;
}
