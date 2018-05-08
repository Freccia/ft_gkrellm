/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:34:25 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/08 12:39:59 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <stdlib.h>

int		main(void)
{
	Phonebook		pb;
	std::string		cmd;
	size_t			index = 0;

	while (42)
	{
		std::cout << "pbb> ";
		std::getline(std::cin, cmd);
		pb.clear_eof();
		if (cmd.empty())
			break;
		if (cmd == "SEARCH")
		{
			pb.SEARCH();
			if (pb.ncont > 0)
			{
				std::cout << "> Contact: ";
				std::getline(std::cin, cmd);
				pb.clear_eof();
				index = atoi(cmd.c_str());
				pb.SELECT(index);
			}
		}
		else if (cmd == "ADD")
			pb.ADD();
		else if (cmd == "EXIT")
			break;
		else if (cmd == "test")
			pb.test();
		else
			std::cout << "Invalid command. (SEARCH/ADD/EXIT)" << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;
}
