/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:02:09 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/29 16:29:49 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

/*
	clang++ -Wall -Wextra -Werror main.cpp
*/

int		usage(std::string name)
{
	std::cout << "Usage: " << name << " string " << std::endl;
	return 1;
}


int		main(int ac, char **av)
{
	if (ac < 2)
		return usage(av[0]);

	/*
	int		n;
	char	c;
	float	f;
	double	d;

	n = std::stoi(av[1]);
	c = n;
	f = std::stof(av[1]);
	d = std::stod(av[1]);
	if (c >= 32 && c <= 127)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
	*/

	std::cout << "char: ";
	try {
		if (std::stoi(av[1]) < std::numeric_limits<char>::min())
			throw std::exception();
		else if (std::stoi(av[1]) > std::numeric_limits<char>::max())
			throw std::exception();
		char c = static_cast<char>(std::stoi(av[1]));
		if (c >= 32 && c <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	} catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
	
	std::cout << "int: ";
	try {
		if (std::stoi(av[1]) < std::numeric_limits<int>::min())
			throw std::exception();
		if (std::stoi(av[1]) > std::numeric_limits<int>::max())
			throw std::exception();
		int n = static_cast<int>(std::stoi(av[1]));
		std::cout << n << std::endl;
	} catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}

	std::cout << "float: ";
	try {
		if (std::stof(av[1]) < std::numeric_limits<float>::min())
			throw std::exception();
		if (std::stof(av[1]) > std::numeric_limits<float>::max())
			throw std::exception();
		float f = static_cast<float>(std::stof(av[1]));
		std::cout << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	} catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}

	std::cout << "double: ";
	try {
		if (std::stod(av[1]) < std::numeric_limits<double>::min())
			throw std::exception();
		if (std::stod(av[1]) > std::numeric_limits<double>::max())
			throw std::exception();
		double d = static_cast<double>(std::stod(av[1]));
		std::cout << d << std::endl;
	} catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}

	return 0;
}
