/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:42:01 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/18 14:20:50 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(void)
{
	// cannot use as it's private (but conform to coplien's form)
	return;
}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << _name
		<< " just popped !" << std::endl;
	return;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << _name
		<< " just died for no apparent reason !" << std::endl;
	return;
}


/*		Member functions	*/

std::string		Victim::introduce(void) const
{
	std::string		phrase = "I'm ";
	phrase.append(_name);
	phrase.append(" and I like otters !\n");
	return phrase;
}


/*		Operators	*/

std::ostream	&operator << (std::ostream &out, Victim const &V) {
	out << V.introduce();
	return out;
}
