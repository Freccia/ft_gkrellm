/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:42:01 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/18 18:18:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include "Victim.hpp"

Peon::Peon(void)
{
	// cannot use as it's private (but conform to coplien's form)
	return;
}

Peon::Peon(std::string name) : Victim(name), _name(name)
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

void			Peon::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a pink pony !"
		<< std::endl;
	return;
}


/*		Operators	*/

std::ostream	&operator << (std::ostream &out, Peon const &P) {
	out << P.Victim::introduce();
	return out;
}
