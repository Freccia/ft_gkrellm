/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:14:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 14:35:02 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():
_name("TUX"),
_level(1),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorReduction(5) {
	std::cout << "A nasty FR4G-TP named " << _name
	<< " is being created !" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name):
_name(name),
_level(1),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorReduction(5) {
	std::cout << "A nasty FR4G-TP named " << _name
	<< " is being created !" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &Cc) {
	*this = Cc;
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

void		FragTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP " << _name << " attacks "
	<< target << " at range, causing " << _rangedAttackDamage
	<< " points of damage !" << std::endl;
	return;
}

void		FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP " << _name << " attacks "
	<< target << ", causing " << _meleeAttackDamage
	<< " points of damage !" << std::endl;
	return;
}

void		FragTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "FR4G-TP " << _name << " is alredy dead !" << std::endl;
		return;
	}
	std::cout << "FR4G-TP " << _name << " takes " << amount
	<< " points of damage !" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints < 0) {
		std::cout << "FR4G-TP " << _name << " died !" << std::endl;
		_hitPoints = 0;
	}
	return;
}

void		FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FR4G-TP " << _name << " is repaired of "  << amount
	<< " points !" << std::endl;
	_hitPoints += amount;
	if (_hitPoints > _maxHitPoints) {
		std::cout << "FR4G-TP " << _name
		<< " is completely repaired !" << std::endl;
		_hitPoints = _maxHitPoints;
	}
	return;
}

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
