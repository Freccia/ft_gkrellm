/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:48:06 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 13:54:08 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 21, 5) {
	return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &Cc) : AWeapon(Cc) {
	*this = Cc;
	return;
}

PlasmaRifle::~PlasmaRifle() {
	return;
}

PlasmaRifle 	&PlasmaRifle::operator = (PlasmaRifle const &Cc) {
	this->_name = Cc._name;
	this->_damage = Cc._damage;
	this->_apcost = Cc._apcost;
	return *this;
}

void 	PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
