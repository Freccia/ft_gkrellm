/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:45:07 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 18:49:10 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void)
{
	std::string		s = "HI THIS IS BRAIN";
	std::string		*p = &s;
	std::string		&r = s;

	std::cout << "Reference(" << &r << "): "<< r << std::endl;
	std::cout << "Pointer(" << p << "): "<< *p << std::endl;
}
