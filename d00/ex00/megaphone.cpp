/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:32:20 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/07 15:56:25 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <new>

std::string		toupperCpp(char *s)
{
	std::string up (s);

	for (size_t i=0; i <= up.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			up[i] = s[i] - 32;
		else
			up[i] = s[i];
	}

	return up;
}

int				main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}

	for (int i=1; i < ac; ++i) {
		std::cout << toupperCpp(av[i]);
	}
	std::cout << "\n";

	return 0;
}
