/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:51:21 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/07 16:45:00 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

int		main(void) {
	intContainer ct = intContainer(5);

	ct.addNumber(5);
	ct.addNumber(3);
	ct.addNumber(17);
	ct.addNumber(9);
	ct.addNumber(11);

	std::cout << ct.shortestSpan() << std::endl;
	std::cout << ct.longestSpan() << std::endl;

	std::cout << "-----------------------------------------------" << std::endl;
	try {
		ct.addNumber(1);
	} catch (intContainer::FullContainer &e) {
		std::cout << "1. " << e.what() << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	intContainer ct2(10001);
	ct2.addNumber(33);
	std::vector<int> v2(10000, 42); // 10000 ints of value 42
	try {
		ct2.addRange(v2.begin(), v2.end());
	} catch (intContainer::FullContainer &e) {
		std::cout << "2. " << e.what() << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	try {
		std::cout << ct2.shortestSpan() << std::endl;
		std::cout << ct2.longestSpan() << std::endl;
	} catch (intContainer::VoidContainer &e) {
		std::cout << "3. " << e.what() << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	try {
		ct2.addRange(v2.begin(), v2.end() - 33);
	} catch (intContainer::FullContainer &e) {
		std::cout << "4. " << e.what() << std::endl;
	}
	std::cout << ct2.shortestSpan() << std::endl;
	std::cout << ct2.longestSpan() << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	intContainer ct3(8);

	ct3.addNumber(30);
	ct3.addNumber(13);
	ct3.addNumber(3);
	ct3.addNumber(2);
	ct3.addNumber(29);
	ct3.addNumber(18);
	ct3.addNumber(14);
	ct3.addNumber(-10);

	std::cout << ct3.shortestSpan() << std::endl;
	std::cout << ct3.longestSpan() << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	intContainer ct4(10001);
	ct4.addNumber(22);
	try {
		ct4.addRange(50, 200);
	} catch (intContainer::FullContainer &e) {
		std::cout << "5. " << e.what() << std::endl;
	}

	std::cout << ct4.shortestSpan() << std::endl;
	std::cout << ct4.longestSpan() << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	return 0;
}
