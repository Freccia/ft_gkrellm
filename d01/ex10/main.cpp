/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:10:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 15:14:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define LINELEN		16

void	catFile(FILE *inFile, FILE* outFile)
{
	char	line[LINELEN];
	int		n = 1;

	while (n > 0) {
		n = read(fileno(inFile), line, LINELEN);
		write(fileno(outFile), line, n);
	}
}

int		main(int ac, char **av)
{
	FILE	*inFile;
	int		ret = 0;
	
	if (ac == 1) {
		catFile(stdin, stdout);
		return 0;
	}

	for (int i=1; i < ac; i++) {
		if ((inFile = fopen(av[i], "r")) != NULL) {
			catFile(inFile, stdout);
		}
		else {
			std::string		err = av[0];
			err.append(": ");
			err.append(av[i]);
			perror(err.c_str());
			ret = 1;
		}
	}
	return 1;
}
