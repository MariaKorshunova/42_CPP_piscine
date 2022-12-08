/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:56:02 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/08 14:41:13 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_CLEAN		"\x1b[0m"

class Base
{
public:
	virtual ~Base() {};
};

class A: public Base { ~A(){}; };
class B: public Base { ~B(){}; };
class C: public Base { ~C(){}; };

Base * generate(void)
{
	int random_variable = std::rand() % 3;
	if (random_variable == 0)
		return new A;
	else if (random_variable == 1)
		return new B;
	return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A* >(p))
		std::cout << "Pointer to object A" << std::endl;
	else if (dynamic_cast<B* >(p))
		std::cout << "Pointer to object B" << std::endl;
	else if (dynamic_cast<C* >(p))
		std::cout << "Pointer to object C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A& >(p);
		std::cout << "Reference to object A" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e){ }
	
	try
	{
		(void) dynamic_cast<B& >(p);
		std::cout << "Reference to object B" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e){ }
	
	try
	{
		(void) dynamic_cast<C& >(p);
		std::cout << "Reference to object C" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e){ }	
}

int main(void)
{
	Base* base;
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 5; i++)
	{
		std::cout << COLOR_YELLOW "Test " << i + 1 << COLOR_CLEAN << std::endl;
		base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
}