/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:12:12 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/26 19:50:20 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BRAIN_HPP
#define CLASS_BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string	ideas[100];

public:
	Brain();
	Brain(const Brain& brain);
	Brain& operator= (const Brain& brain);
	~Brain();

	const std::string& getIdea(const unsigned int i) const;
	void	setIdea(const std::string& str, const unsigned int i);
	
};

#endif // CLASS_BRAIN_HPP