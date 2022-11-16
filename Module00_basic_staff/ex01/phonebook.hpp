/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:24:54 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/16 18:02:00 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
// #include "contact.hpp"

class PhoneBook
{
private:
    // Contact	contacts[8];

	std::string	readValue(std::string promptMessage);
    
public:
    PhoneBook();
    ~PhoneBook();

    void	addContact();
};

#endif