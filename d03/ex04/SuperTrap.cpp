/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:32:18 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 17:37:05 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

/*		Constructors - Desctructors		*/

SuperTrap::SuperTrap() :
	ClapTrap("SuperTramp", 1, 100, 100, 120, 120, 60, 20, 5),
	FragTrap(ClapTrap::_name),
	NinjaTrap(ClapTrap::_name)
{
	std::cout << "A notorious SUP3R-TP named " << _name
	<< " is being created !" << std::endl;
	/*
	_hitPoints = FragTrap::_hitPoints;
	_maxHitPoints = FragTrap::_maxHitPoints;
	_energyPoints = NinjaTrap::_energyPoints;
	_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
	_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
	_rangedAttackDamage = FragTrap::_rangedAttackDamage;
	_armorReduction = FragTrap::_armorReduction;
	*/
	return;
}

SuperTrap::SuperTrap(std::string name) :
	ClapTrap(name, 1, 100, 100, 120, 120, 60, 20, 5),
	FragTrap(ClapTrap::_name),
	NinjaTrap(ClapTrap::_name)
{
	std::cout << "A notorious SUP3R-TP named " << _name
	<< " is being created !" << std::endl;
	/*
	_hitPoints = FragTrap::_hitPoints;
	_maxHitPoints = FragTrap::_maxHitPoints;
	_energyPoints = NinjaTrap::_energyPoints;
	_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
	_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
	_rangedAttackDamage = FragTrap::_rangedAttackDamage;
	_armorReduction = FragTrap::_armorReduction;
	*/
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

