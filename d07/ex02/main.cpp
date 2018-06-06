/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:10:51 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/06 15:18:01 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int		main(void)
{
	size_t		size = 42;
	Array<int>	lol(size);

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Created string of size: " << lol.size() << std::endl;

	for (size_t i=0; i < size; i++) {
		lol[i] = (i + 1) * 10;
	}
	for (size_t i=size/2; i < size; i++) {
		std::cout << i << ":    " << lol[i] << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Cloning array..." << std::endl;
	Array<int>	lul(lol);

	for (size_t i=0; i < size; i++) {
		if (lul[i] != lol[i])
			std::cout << i << ": differs " << lol[i] << " - " << lul[i] << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Copying array..." << std::endl;
	Array<int>	lel(0);

	lel = lol;
	for (size_t i=0; i < size; i++) {
		if (lel[i] != lol[i])
			std::cout << i << ": differs " << lol[i] << " - " << lel[i] << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Creating an empty array" << std::endl;
	Array<int>	hey(0);
	std::cout << "Accessing arr[1]: " << std::endl;

	try { if (lol[300] == 0) std::cout << "No exception" << std::endl; }
	catch (Array<int>::OperatorOutOfRange &e)
		{ std::cout << e.what() << std::endl; };

	/*
	std::cout << "-----------------------------------------------" << std::endl;
	try { if (lol[300] == 0) std::cout << "No exception" << std::endl; }
	catch (std::exception &e)
		{ std::cout << e.what() << std::endl; };
	*/
	std::cout << "-----------------------------------------------" << std::endl;
	return 0;
}
