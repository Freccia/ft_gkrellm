/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:10:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 14:08:54 by lfabbro          ###   ########.fr       */
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
	Cat				cat("");
	bool			ret = true;

	if (ac > 1) {
		for (int i=1; i < ac; i++) {
			cat.setFile(av[i]);
			do {
				cat.write();
			} while (cat.read());
			cat.close();
		}
	}
	else
		while (ret) {
			cat.read();
			cat.write();
		}
	return 0;
}
