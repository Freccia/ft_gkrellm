/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:24:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 19:14:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name(""), _amount(0) {
	return;
}

Character::Character(Character const & Cc) :
	_name(Cc._name), _amount(Cc._amount)
{
	for (unsigned int i = 0; i < this->_amount; i++) {
		this->_inventory[i] = Cc._inventory[i]->clone();
	}
	return;
}

Character::~Character(void) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		delete this->_inventory[i];
	}
	return;
}

Character::Character(std::string const & name) : _name(name), _amount(0){
	return;
}

Character & Character::operator = (Character const & Cc) {
	this->~Character();
	this->_name = Cc._name;
	this->_amount = Cc._amount;
	for (unsigned int i = 0; i < this->_amount; i++) {
		this->_inventory[i] = Cc._inventory[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	if (!m or this->_amount == 4)
		return;
	this->_inventory[this->_amount] = m;
	this->_amount++;
}

void Character::unequip(int idx) {
	if ((unsigned int)idx >= this->_amount)
		return;
	if ((unsigned int)idx == this->_amount - 1) {
		this->_amount--;
		return;
	}
	for (unsigned int i = (unsigned int)idx + 1; i < this->_amount; i++) {
		this->_inventory[i - 1] = this->_inventory[i];
	}
	this->_amount--;
}

void Character::use(int idx, ICharacter& target) {
	if ((unsigned int)idx >= this->_amount)
		return;
	this->_inventory[idx]->use(target);
}
