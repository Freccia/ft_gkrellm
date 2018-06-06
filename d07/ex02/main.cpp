/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:10:51 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/06 14:44:38 by lfabbro          ###   ########.fr       */
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
	for (size_t i=size/3; i < size; i++) {
		std::cout << i << ":    " << lol[i] << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Creating an empty array" << std::endl;
	Array<int>	hey(0);
	std::cout << "Accessing arr[1]: " << std::endl;
	try { if (hey[0] == 0) std::cout << "No exception" << std::endl; }
	catch (std::exception &e)
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
