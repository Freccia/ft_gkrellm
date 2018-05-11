/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:12:30 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 12:00:57 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <ios>
#include <stdlib.h>

void		usage(std::string name)
{
	std::cout << "Usage: " << name <<
		" inputFile stringToReplace replaceString" << std::endl;
	std::cout << "	(stringToReplace cannot be empty)" << std::endl;
	exit(1);
}

int			main(int ac, char **av)
{
	std::string		inFileName;
	std::string		outFileName;
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		line;
	size_t			found;
	std::string		s1;
	std::string		s2;

	if (ac != 4)
		usage(av[0]);

	inFileName = av[1];
	outFileName = av[1];
	outFileName.append(".replace");

	s1 = av[2];
	s2 = av[3];

	if (s1.empty())
		usage(av[0]);

	inFile.open(inFileName.c_str());
	outFile.open(outFileName.c_str(), std::ios::out);
	if (!inFile || !outFile) {
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}

	std::cout << "Replacing string '" << s1 << "' with '" << s2
		<< "' in file " << inFileName << std::endl;

	while (getline(inFile, line)) {
		while ((found = line.find(s1)) != std::string::npos) {
			line.replace(found, s1.length(), s2);
		}
		outFile << line;
		outFile << std::endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}
