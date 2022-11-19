/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:24:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/19 20:14:42 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define COLOR_RED "\x1b[31m"
#define COLOR_CLEAN "\x1b[0m"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << COLOR_RED "Invalid number of arguments" COLOR_CLEAN << std::endl;
		return 1;
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cerr << COLOR_RED "Arguments can't be empty" COLOR_CLEAN << std::endl;
		return 1;		
	}
	
	std::ifstream	infile(filename);
	if (!infile.is_open())
	{
		std::cerr << filename << COLOR_RED " can't be open" COLOR_CLEAN << std::endl;
		return 2;
	}
	
	std::ofstream	outfile(filename + ".replace");
	if (!infile.is_open())
	{
		infile.close();
		std::cerr << filename + ".replace" << COLOR_RED " can't be open" COLOR_CLEAN << std::endl;
		return 2;
	}

	std::string	line;
	size_t	pos;
	size_t	s1Len = s1.length();
	size_t	s2Len = s2.length();
	while (std::getline(infile, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1Len);
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2Len);
		}
		outfile << line << '\n';
	}
	
	infile.close();
	outfile.close();

	return 0;
}