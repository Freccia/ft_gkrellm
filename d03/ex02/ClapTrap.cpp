/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:00:24 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 12:28:01 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
_name("Cl4p-TP"), _level(1), _hitPoints(100), _maxHitPoints(100),
_energyPoints(50), _maxEnergyPoints(50), _meleeAttackDamage(10),
_rangedAttackDamage(10), _armorReduction(1)
{
	return;
}

ClapTrap::ClapTrap(std::string name) :
_name(name), _level(1), _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
_maxEnergyPoints(50), _meleeAttackDamage(10), _rangedAttackDamage(10),
_armorReduction(1)
{
	return;
}

ClapTrap::ClapTrap(std::string name, int level, int hitPoints, int maxHitPoints,
		int energyPoints, int maxEnergyPoints, int meleeAttack, int rangedAttack,
		int armorReduction)
{
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
	*this = Cc;
	return;
}

ClapTrap::~ClapTrap()
{
	return;
}
