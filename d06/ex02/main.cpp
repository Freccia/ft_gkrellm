/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:24:24 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/04 17:30:35 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // sleep

Base *generate(void) {
	srand(std::time(0));
	int r = rand() % 3;

	if (r == 0)
	{
		return (new A);
	}
	else if (r == 1)
	{
		return (new B);
	}
	else
	{
		return (new C);
	}
}

void identify_from_pointer(Base *p) {
	if (A *a = dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (B *b = dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (C *c = dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
}

void identify_from_reference(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {}

	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}

	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}

int main() {
	Base *ptr;

	ptr = generate();
	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	sleep(1);

	ptr = generate();
	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	sleep(1);

	ptr = generate();
	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	return 0;
}
