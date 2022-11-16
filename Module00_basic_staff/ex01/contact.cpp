/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:00:00 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/16 16:23:01 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::SetFirstName(std::string firstName){ m_firstName = firstName; }
void	Contact::SetLastName(std::string lastName){ m_lastName = lastName; }
void	Contact::SetNickName(std::string nickName){ m_nickName = nickName; }
void	Contact::SetPhoneNumber(std::string phoneNumber){ m_phoneNumber = phoneNumber; }
void	Contact::SetDarkestSecret(std::string darkestSecret){ m_darkestSecret = darkestSecret; }

std::string	Contact::GetFirstName() { return m_firstName; }
std::string	Contact::GetLastName() { return m_lastName; }
std::string	Contact::GetNickName() { return m_nickName; }
std::string	Contact::GetPhoneNumber() { return m_phoneNumber; }
std::string	Contact::GetDarkestSecret() { return m_darkestSecret; }