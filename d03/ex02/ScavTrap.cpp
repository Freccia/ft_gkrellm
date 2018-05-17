/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:14:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 14:41:41 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*		Constructors - Desctructors		*/

ScavTrap::ScavTrap() :
	ClapTrap("R0M", 1, 100, 100, 50, 50, 20, 15, 3)
{
	std::cout << "A misterious SC4V-TP named " << _name
	<< " appeared !" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name, 1, 100, 100, 50, 50, 20, 15, 3)
{
	std::cout << "A misterious SC4V-TP named " << _name
	<< " appeared !" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &Cc) :
	ClapTrap(Cc)
{
	//*this = Cc;
	std::cout << "A misterious SC4V-TP named " << _name
	<< " is being cloned !" << std::endl;
	return;
}

ScavTrap::~ScavTrap() {
	std::cout << "A misterious SC4V-TP named " << _name
	<< " is destructed !" << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &Cc) {
	ClapTrap::operator = (Cc);
	return *this;
}


/*		Member Functions		*/

void		ScavTrap::challengeNewcomer(std::string const & target) {
/*
	if (_energyPoints < 25) {
		std::cout << "SC4V-TP " << _name
		<< " has not enough energy, the attack failed !" << std::endl;
		return;
	}
	*/
	std::string		riddles[] = {
		"I travel all over the world, but always stay in my corner. What am I?",
		"Which is the most curious letter?",
		"A kind of tree can you carry in your hand?",
		"I can fly, I can crawl, I have hands but no wings or legs. What am I?",
		"What is easy to get into, but hard to get out of?"};
	std::string		answers[] = {
		"A stamp",
		"Y?",
		"A palm",
		"Time",
		"Trouble"};
	std::srand(std::time(0));
	int				n = std::rand() % 5;
	std::cout << "SC4V-TP " << _name << ": " << riddles[n] << std::endl;
	std::cin.ignore();
	std::cout << target << ": " << answers[n] << std::endl;
	std::cout << std::endl;
	/*
	_energyPoints -= 25;
	*/
	return;
}
