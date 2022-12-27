/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:47:25 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/27 15:56:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock
{
private:
	std::string	name;
	std::string title;
	std::map<std::string, ASpell* > map;

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

	void learnSpell(ASpell* spell) { map[spell->getName()] = spell; }
	void forgetSpell(std::string spell) { map.erase(spell); }
	
	void launchSpell(std::string spell, ATarget& target)
	{
		if (map[spell])
			map[spell]->launch(target);
	}
};
