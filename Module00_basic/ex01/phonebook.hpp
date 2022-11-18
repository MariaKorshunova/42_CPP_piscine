/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:24:54 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/18 15:54:30 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook
{
private:
    Contact	m_contacts[8];
    int     m_nextIndex;

	std::string	readValue(std::string promptMessage);
    void		printContacts();;
	void		print10(std::string str);
    void		printOneContact(int i);
    
public:
    PhoneBook();
    ~PhoneBook();

    void	addContact();
    void	searchContact();
};

#endif