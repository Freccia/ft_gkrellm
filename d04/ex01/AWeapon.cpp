/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:37:12 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 13:52:19 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() {
	return;
}

AWeapon::AWeapon(std::string const & name, int damage, int apcost) :
		_name(name),
		_damage(damage),
		_apcost(apcost) {
	return;
}

AWeapon::AWeapon(AWeapon const &Cc) {
	*this = Cc;
	return;
}

AWeapon::~AWeapon() {
	return;
}

AWeapon 	&AWeapon::operator = (AWeapon const &Cc) {
	this->_name = Cc._name;
	this->_damage = Cc._damage;
	this->_apcost = Cc._apcost;
	return *this;
}

std::string 	AWeapon::getName() const {
	return this->_name;
}

int 			AWeapon::getAPCost() const {
	return this->_apcost;
}

int 			AWeapon::getDamage() const {
	return this->_damage;
}

