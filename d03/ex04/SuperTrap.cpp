/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:32:18 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 15:52:51 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

/*		Constructors - Desctructors		*/

SuperTrap::SuperTrap() :
	ClapTrap("SuperTramp", 1, 100, 100, 100, 100, 30, 20, 5)
{
	std::cout << "A notorious SUP3R-TP named " << _name
	<< " is being created !" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	return;
}

SuperTrap::SuperTrap(std::string name) :
	ClapTrap(name, 1, 100, 100, 100, 100, 30, 20, 5)
{
	std::cout << "A notorious SUP3R-TP named " << _name
	<< " is being created !" << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const &Cc) :
	ClapTrap(Cc)
{
	//*this = Cc;
	std::cout << "A notorious SUP3R-TP named " << _name
	<< " is being cloned !" << std::endl;
	return;
}

SuperTrap::~SuperTrap() {
	std::cout << "The notorious SUP3R-TP named " << _name
	<< " is destructed !" << std::endl;
	return;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &Cc) {
	ClapTrap::operator = (Cc);
	return *this;
}


/*		Member Functions		*/

