/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:42:01 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/18 14:21:19 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
{
	// cannot use as it's private (but conform to coplien's form)
	return;
}

Sorcerer::Sorcerer(std::string name, std::string title) :
	_name(name), _title(title)
{
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << _name << ", " << _title
		<< ", is dead. Consequences will never be the same !" << std::endl;
	return;
}


/*		Member functions	*/

std::string		Sorcerer::introduce(void) const
{
	std::string		phrase = "I am ";
	phrase.append(_name);
	phrase.append(", ");
	phrase.append(_title);
	phrase.append(", and I like ponies !\n");
	return phrase;
}


/*		Operators	*/

std::ostream	&operator << (std::ostream &out, Sorcerer const &S) {
	out << S.introduce();
	return out;
}
