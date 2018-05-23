/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:49:03 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 13:52:31 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 50, 8) {
	return;
}

PowerFist::PowerFist(PowerFist const &Cc) : AWeapon(Cc) {
	*this = Cc;
	return;
}

PowerFist::~PowerFist() {
	return;
}

PowerFist 	&PowerFist::operator = (PowerFist const &Cc) {
	this->_name = Cc._name;
	this->_damage = Cc._damage;
	this->_apcost = Cc._apcost;
	return *this;
}

void 	PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
