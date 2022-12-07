/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:26:39 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/07 19:41:30 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Converter.hpp"

int	main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid number of argument" << std::endl;
        return (EXIT_FAILURE);
    }
    Converter converter;
    std::string value = argv[1];
    converter.convert(value);
    return (EXIT_SUCCESS);
}