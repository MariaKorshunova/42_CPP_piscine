/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:13:24 by jmabel            #+#    #+#             */
/*   Updated: 2023/06/13 19:45:48 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PMERGEME_HPP
#define CLASS_PMERGEME_HPP

#include <iostream>
#include <vector>

class PmergeMe {
    
    private:
        int					_argc;
        char**				_argv;
		std::vector<int>	_sequence;

		bool	validate_input();

    public:
		PmergeMe();
        PmergeMe(int& argc, char** (&argv));
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& copy);
        ~PmergeMe();


        class PmergeMeException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error";
				}
		};
};

# endif //CLASS_PMERGEME_HPP