/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:54:31 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/14 11:31:44 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cstdlib>

void	usage(std::string name) {
	std::cout << "Usage: " << name << " expr1 [expr2, ...]"<< std::endl;
	exit(1);
}

int		main(int ac, char **av) {
	Fixed a;
	Fixed b;

	if (ac <= 1)
		usage(av[0]);

	return 0;
}
