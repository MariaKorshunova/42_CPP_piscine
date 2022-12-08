/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:52:37 by jmabel            #+#    #+#             */
/*   Updated: 2022/12/08 13:13:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
	std::string	name;
	float			level;
};

uintptr_t serialize(Data* ptr)
{
	uintptr_t	uintptr = reinterpret_cast<uintptr_t>(ptr);
	return uintptr;
}

Data*	deserialize(uintptr_t uintptr)
{
	struct Data* ptr;
	ptr = reinterpret_cast<Data* >(uintptr);
	return ptr;
}

int	main(void)
{
	struct Data		jmabel;
	struct Data*	jmabel_ptr;
	
	jmabel.name = "jmabel";
	jmabel.level = 4.75f;
	std::cout << "Info from Data: name " << jmabel.name <<
				 "\tlevel: " << jmabel.level << std::endl;
	
	uintptr_t	uintptrData = serialize(&jmabel);
	jmabel_ptr = deserialize(uintptrData);
		std::cout << "Info from deserialize pointer to Data: name " <<
					jmabel_ptr->name << "\tlevel: " << jmabel_ptr->level << std::endl;
	return 0;
}