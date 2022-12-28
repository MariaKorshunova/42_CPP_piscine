/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:47:25 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/28 15:10:11 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	std::string	name;
	std::string title;
	SpellBook book;

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

	void learnSpell(ASpell* spell) { book.learnSpell(spell); }
	void forgetSpell(std::string spell) { book.forgetSpell(spell); }
	
	void launchSpell(std::string spell, ATarget& target)
	{
		ASpell *tmp = book.createSpell(spell);
		if (tmp)
			tmp->launch(target);
	}
};
