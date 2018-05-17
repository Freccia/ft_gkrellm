/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:14:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 17:00:01 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*		Constructors - Desctructors		*/

FragTrap::FragTrap() :
	ClapTrap("TuX", 1, 100, 100, 100, 100, 30, 20, 5)
{
	std::cout << "A nasty FR4G-TP named " << _name
	<< " is being created !" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) :
	ClapTrap(name, 1, 100, 100, 100, 100, 30, 20, 5)
{
	std::cout << "A nasty FR4G-TP named " << _name
	<< " is being created !" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &Cc) :
	ClapTrap(Cc)
{
	//*this = Cc;
	std::cout << "A nasty FR4G-TP named " << _name
	<< " is being cloned !" << std::endl;
	return;
}

FragTrap::~FragTrap() {
	std::cout << "The nasty FR4G-TP named " << _name
	<< " is destructed !" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &Cc) {
	ClapTrap::operator = (Cc);
	return *this;
}


/*		Member Functions		*/

void		FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (_energyPoints < 25) {
		std::cout << "FR4G-TP " << _name
		<< " has not enough energy, the attack failed !" << std::endl;
		return;
	}
	std::string		attacks[] = {
		"vomit bolt", "kitty", "roulette wheel", "gas fart", "towel"};
	std::srand(std::time(0));
	std::cout << "FR4G-TP " << _name << " attacks " << target << " with a "
	<< attacks[std::rand() % 5] << std::endl;
	_energyPoints -= 25;
	return;
}
