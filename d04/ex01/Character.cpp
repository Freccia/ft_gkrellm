/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:17:12 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 14:27:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	return;
}

Character::Character(std::string const & name) : _name(name) {
	this->_ap = 40;
	this->_weapon = NULL;
	return;
}

Character::Character(Character const &Cc) {
	*this = Cc;
	return;
}

Character::~Character() {
	return;
}

Character &Character::operator = (Character const &Cc) {
	this->_ap = Cc._ap;
	this->_name = Cc._name;
	this->_weapon = Cc._weapon;
	return *this;
}

void 	Character::recoverAP() {
	this->_ap += 10;
	if ((this->_ap) > 40)
		this->_ap = 40;
}

void 	Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

void 	Character::attack(Enemy *en) {
	if (_weapon == NULL)
		std::cout << this->_name << "has " << this->_ap
			<< " AP and is unarmed" << std::endl;
	else {
		if (_weapon->getAPCost() <= this->_ap) {
			this->_ap -= _weapon->getAPCost();
			std::cout << this->_name << " attacks " << en->getType()
				<< " with a " << this->_weapon->getName() << std::endl;
			_weapon->attack();
			en->takeDamage(_weapon->getDamage());
			if (en->getHP() == 0) {
				delete en;
			}
		}
		else {
			std::cout << "Not enough AP." << std::endl;
		}
	}
}

std::string		Character::getName() const {
	return this->_name;
}

int			Character::getAP() const {
	return this->_ap;
}

std::string		Character::getWeaponName() const {
	if (_weapon == NULL)
		return NULL;
	return this->_weapon->getName();
}

AWeapon		*Character::getWeapon() const {
	return this->_weapon;
}

std::ostream 	&operator << (std::ostream &out, Character const &Cc) {
	if (Cc.getWeapon())
		out << Cc.getName() << " has " << Cc.getAP() << " AP and wields a "
			<< Cc.getWeaponName() << std::endl;
	else
		std::cout << Cc.getName() << " has " << Cc.getAP()
			<< " AP and is unarmed" << std::endl;
	return out;
}

