/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:25:02 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/13 19:46:47 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int& argc, char** (&argv)) {
    _argc = argc;
    _argv = argv;
    if (!validate_input())
		throw PmergeMeException();
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
	if (this == &copy)
		return *this;
	this->_argc = copy._argc;
	this->_argv = copy._argv;
    this->_sequence = copy._sequence;
	return *this;
}

PmergeMe::~PmergeMe() {}

bool	PmergeMe::validate_input() {
    for (int i = 1; i < _argc; i++) {
        std::string str(_argv[i]);
        for (size_t j = 0; j < str.size(); j++) {
            if (!isdigit(str[j]))
                return false;
            _sequence.push_back(atoi(str.c_str()));
        }
    }
    return true;
}