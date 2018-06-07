/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:03:06 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/07 12:51:03 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include "easyfind.hpp"

int		main(void)
{
	std::list<int> intList;
	intList.push_back(10);
	intList.push_back(3);
	intList.push_back(1);
	intList.push_back(5);
	intList.push_back(12);
	intList.push_back(42);
	intList.push_back(1);
//	intList.push_back(100);

	std::list<int>::const_iterator ret = easyfind< std::list<int> >(intList, 42);
	std::cout << "Found: " << *ret << std::endl;

	std::vector<int> intVector(3, 42);
	intVector[0] = 35;
	std::vector<int>::const_iterator ret2 = easyfind< std::vector<int> >(intVector, 35);
	std::cout << "Found: " << *ret2 << std::endl;

	std::list<int>::const_iterator ret3;
	try {
		 ret3 = easyfind< std::list<int> >(intList, 100);
	}
	catch (std::exception &	e) {
		std::cout << e.what() << std::endl;
	}
//	std::cout << "Found: " << *ret3 << std::endl;

	return 0;
}
