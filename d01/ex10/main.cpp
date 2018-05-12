/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:10:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 12:33:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

/*
void	usage(std::string name)
{
	std::cout << "Usage: " << name << " [inFileName, outFileName]" << std::endl;
	exit(1);
}
*/

int		main(int ac, char **av)
{
	std::string		inFileName;
	std::string		outFileName;

	if (ac < 3) {
		inFileName = "";
		outFileName = "";
	}
	else if (ac == 3) {
		inFileName = av[1];
		outFileName = av[2];
	}

	Cat		cat(inFileName, outFileName);

	while (cat.eofBit() == 0) {
		cat.read();
		cat.writeLine();
	}
	return 0;
}
