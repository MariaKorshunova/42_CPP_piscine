/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:47:26 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/11 21:07:20 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_CLEAN		"\x1b[0m"

int	main(void)
{
	{
		std::cout << COLOR_YELLOW "\nTest 0: from subject" COLOR_CLEAN << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span	span(10);
		
		std::cout << COLOR_YELLOW "\nTest 1: fill array" COLOR_CLEAN << std::endl;
		srand(static_cast<unsigned int>(time(0)));
		for (unsigned int i = 0; i < 10; i++)
			span.addNumber(std::rand() % 100);
		span.print();

		std::cout << COLOR_YELLOW "\nTest 2: exception with full array" COLOR_CLEAN << std::endl;
		try { span.addNumber(42); }
		catch(std::exception& e) { std::cerr << e.what() << std::endl; }

		std::cout << COLOR_YELLOW "\nTest 3: Span with size of array less than 2" COLOR_CLEAN << std::endl;
		Span	smallSpan(1);
		smallSpan.addNumber(42);
		smallSpan.print();
		try { std::cout << "shortestSpan: " << smallSpan.shortestSpan() << std::endl; }
		catch(std::exception& e) { std::cerr << e.what() << std::endl;}
		try { std::cout << "longestSpan: " << smallSpan.longestSpan() << std::endl; }
		catch(std::exception& e) { std::cerr << e.what() << std::endl;}

		std::cout << COLOR_YELLOW "\nTest 4: shortestSpan" COLOR_CLEAN << std::endl;
		span.print();
		std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << span.longestSpan() << std::endl;

		std::cout << COLOR_YELLOW "\nTest 5: 10 000 elements" COLOR_CLEAN << std::endl;
		Span bigSpan(10000);
		for (unsigned int i = 0; i < 10000; i++)
			bigSpan.addNumber(std::rand() % 100);
		std::cout << "shortestSpan: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << bigSpan.longestSpan() << std::endl;
	}
}