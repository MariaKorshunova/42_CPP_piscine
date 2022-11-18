/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:31:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/17 16:21:07 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_nickName;
	std::string m_phoneNumber;
	std::string m_darkestSecret;

public:
	Contact();
	~Contact();

	void	SetFirstName(std::string firstName);
	void	SetLastName(std::string lastName);
	void	SetNickName(std::string nickName);
	void	SetPhoneNumber(std::string phoneNumber);
	void	SetDarkestSecret(std::string darkestSecret);

	std::string	GetFirstName();
	std::string	GetLastName();
	std::string	GetNickName();
	std::string	GetPhoneNumber();
	std::string	GetDarkestSecret();
};

#endif