/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:00:24 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 15:15:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*		Constructors - Desctructors		*/

ClapTrap::ClapTrap() :
_name("Cl4p-TP"), _level(1), _hitPoints(100), _maxHitPoints(100),
_energyPoints(50), _maxEnergyPoints(50), _meleeAttackDamage(10),
_rangedAttackDamage(10), _armorReduction(1)
{
	std::cout << "Default ClapTrap constructor" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) :
_name(name), _level(1), _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
_maxEnergyPoints(50), _meleeAttackDamage(10), _rangedAttackDamage(10),
_armorReduction(1)
{
	std::cout << "ClapTrap(name) constructor" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name, int level, int hitPoints, int maxHitPoints,
		int energyPoints, int maxEnergyPoints, int meleeAttack, int rangedAttack,
		int armorReduction)
{
	std::cout << "ClapTrap(..) constructor" << std::endl;
	_name = name;
	_level = level;
	_hitPoints = hitPoints;
	_maxHitPoints = maxHitPoints;
	_energyPoints = energyPoints;
	_maxEnergyPoints = maxEnergyPoints;
	_meleeAttackDamage = meleeAttack;
	_rangedAttackDamage = rangedAttack;
	_armorReduction = armorReduction;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &Cc)
{
	std::cout << "ClapTrap Copy constructor" << std::endl;
	*this = Cc;
	return;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
	return;
}


/*		Member Functions		*/

void		ClapTrap::rangedAttack(std::string const & target) {
	std::cout << _name << " hits "
		<< target << " at range, causing "
		<< _rangedAttackDamage << " points of damage !" << std::endl;
	return;
}

void		ClapTrap::meleeAttack(std::string const & target) {
	std::cout << _name << " beats "
		<< target << ", causing "
		<< _meleeAttackDamage << " points of damage !" << std::endl;
	return;
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << _name << " is alredy dead !" << std::endl;
		return;
	}
	std::cout << _name << " is hit of "
		<< amount << " points of damage !" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints < 0) {
		std::cout << _name << " died !" << std::endl;
		_hitPoints = 0;
	}
	return;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	std::cout << _name << " is repaired of "
		<< amount << " points !" << std::endl;
	_hitPoints += amount;
	if (_hitPoints >= _maxHitPoints) {
		std::cout << _name << " is completely repaired !" << std::endl;
		_hitPoints = _maxHitPoints;
	}
	return;
}


/*		Operators		*/

ClapTrap	&ClapTrap::operator = (ClapTrap const & Cc)
{
	_name = Cc._name;
	_level = Cc._level;
	_hitPoints = Cc._hitPoints;
	_maxHitPoints = Cc._maxHitPoints;
	_energyPoints = Cc._energyPoints;
	_maxEnergyPoints = Cc._maxEnergyPoints;
	_meleeAttackDamage = Cc._meleeAttackDamage;
	_rangedAttackDamage = Cc._rangedAttackDamage;
	_armorReduction = Cc._armorReduction;
	return *this;
}
