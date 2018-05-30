/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:54:31 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/30 13:21:48 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cstdlib> // exit()

/*	Globals	*/
std::stringstream	expr;


int			usage(std::string name) {
	std::cout << "Usage: " << name << " expr1 [expr2, ...]"<< std::endl;
		return -1;
}


/*	Recursive descent parser	*/

Fixed		expression_eval();;

char		peek()
{
	char	c = expr.get();
	expr.unget();
	return c;
}

char		get()
{
	return expr.get();
}


Fixed		number()
{
	float	f;

	expr >> f;
	Fixed	result(f);
	return result;
}

Fixed		factor()
{
	while (peek() == ' ')
		get();

	if (peek() >= '0' && peek() <= '9')
		return number();
	else if (peek() == '(')
	{
		get(); // '('
		Fixed result = expression_eval();
		get(); // ')'
		return result;
	}
	else if (peek() == '-')
	{
		get();
		return -factor();
	}
	std::cout << "Expresion error" << std::endl;
	exit(1);
}

Fixed		calculate()
{
	Fixed	result = factor();
	char	c;

	while ((c = peek()) == '*' || c == '/' || c == ' ') {
		c = get();
		if (c == '*')
			result = result * factor();
		else if (c == '/')
		{
			try { result = result / factor(); }
			catch (std::exception &e) {
				std::cerr << e.what() << " Abort." << std::endl;
				exit(1);
			}
		}
	}
	return result;
}

Fixed		expression_eval()
{
	Fixed	result = calculate();
	char	c;

	while ((c = peek()) == '+' || c == '-' || c == ' ') {
		c = get();
		if (c == '+')
			result = result + calculate();
		else if (c == '-')
			result = result - calculate();
	}
	return result;
}

/*							*/


int			main(int ac, char **av)
{
	Fixed result;

	if (ac <= 1)
		return usage(av[0]);

	for (int i=1; i < ac; i++)
	{
		expr.clear();
		expr.str (av[i]);
		result = expression_eval();
		//std::cout << av[i] << " = " << result << std::endl;
		std::cout << result << std::endl;
	}

	return 0;
}
