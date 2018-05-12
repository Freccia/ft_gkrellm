/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 10:42:36 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 11:12:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include <iostream>
#include <stdlib.h>

void	usage(std::string name)
{
	Logger			lgr("");
	std::string		usg;

	usg = "Usage: ";
	usg.append(name);
	usg.append(" logFile [msg1, msg2, ...]");
	lgr.log("logToConsole", usg);
	lgr.log("logToConsole", "This is a test to errrrrrrr!");
	exit(1);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		usage(av[0]);

	Logger	lgr(av[1]);

	for (int i=2; i < ac; i++) {
		lgr.log("logToFile", av[i]);
	}
	return 0;
}
