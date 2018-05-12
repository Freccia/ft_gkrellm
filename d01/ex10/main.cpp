/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:10:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 14:52:28 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <errno.h>

#define LINELEN		16

/*
void	catFile(FILE *inFile, FILE* outFile)
{
	char	line[LINELEN];
	int		lineno = 1;

	while (fgets(line, LINELEN, inFile)) {
		if (fputs(line, outFile) == EOF) {
			perror("Write to stdout failed.");
			return;
		}

		++lineno;
	}
}
*/

int		main(int ac, char **av)
{
	std::string		str;
	std::ifstream	inFile;
	
	if (ac < 2) {
		do {
			getline(std::cin, str);
			std::cout << str;
		} while (std::cin.eof() == false);
		return 0;
	}

	for (int i=0; i < ac; i++) {
		inFile.open(av[i]);
		if (inFile.is_open()) {
			while (inFile.is_open())
				inFile >> str;
				std::cout << str;
			inFile.close();
		}
		else
		{
			std::string		err = av[0];
			err.append(": ");
			err.append(av[i]);
			perror(err.c_str());
		}
	}
	return 0;
}
