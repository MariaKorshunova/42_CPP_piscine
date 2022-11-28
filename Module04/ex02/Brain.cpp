/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:31:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 20:47:16 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called"<< std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
}

Brain& Brain::operator= (const Brain& brain)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this == &brain)
		return *this;
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

const std::string& Brain::getIdea(const unsigned int i) const
{
	return ideas[i % 100];
}

void	Brain::setIdea(const std::string& str, const unsigned int i)
{
	ideas[i % 100] = str;
}