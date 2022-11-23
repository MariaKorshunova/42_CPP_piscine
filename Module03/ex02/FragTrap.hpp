/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:11:20 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/23 19:19:32 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(const std::string name);

	FragTrap(const FragTrap &fragtrap);
	FragTrap& operator= (const FragTrap &fragtrap);
	~FragTrap();

	void 	highFivesGuys(void);
	void	attack(const std::string& target);
};

#endif