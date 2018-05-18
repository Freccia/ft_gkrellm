/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:42:01 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/18 14:35:05 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include "Victim.hpp"

Peon::Peon(void)
{
	// cannot use as it's private (but conform to coplien's form)
	return;
}

Peon::Peon(std::string name) : _name(name)
{
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
	return;
}


/*		Member functions	*/


/*		Operators	*/

std::ostream	&operator << (std::ostream &out, Peon const &P) {
	out << P.Victim::introduce();
	return out;
}
