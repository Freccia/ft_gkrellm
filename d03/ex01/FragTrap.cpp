/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:14:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/16 12:29:43 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():
_name("R0M"),
_level(1),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(50),
_maxEnergyPoints(50),
_meleeAttackDamage(20),
_rangedAttackDamage(15),
_armorReduction(3) {
	std::cout << "A misterious SC4V-TP named " << _name
	<< " appeared !" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name):
_name(name),
_level(1),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(50),
_maxEnergyPoints(50),
_meleeAttackDamage(20),
_rangedAttackDamage(15),
_armorReduction(3) {
	std::cout << "A misterious SC4V-TP named " << _name
	<< " appeared !" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &Cc) {
	*this = Cc;
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

void		ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "SC4V-TP " << _name << " hits "
	<< target << " at range, causing " << _rangedAttackDamage
	<< " points of damage !" << std::endl;
	return;
}

void		ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "SC4V-TP " << _name << " beats "
	<< target << ", causing " << _meleeAttackDamage
	<< " points of damage !" << std::endl;
	return;
}

void		ScavTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "SC4V-TP " << _name << " is alredy dead !" << std::endl;
		return;
	}
	std::cout << "SC4V-TP " << _name << " is hit of " << amount
	<< " points of damage !" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints < 0) {
		std::cout << "SC4V-TP " << _name << " died !" << std::endl;
		_hitPoints = 0;
	}
	return;
}

void		ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "SC4V-TP " << _name << " is repaired of "  << amount
	<< " points !" << std::endl;
	_hitPoints += amount;
	std::cout << _hitPoints << std::endl;
	if (_hitPoints >= _maxHitPoints) {
		std::cout << "SC4V-TP " << _name
		<< " is completely repaired !" << std::endl;
		_hitPoints = _maxHitPoints;
	}
	return;
}

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
