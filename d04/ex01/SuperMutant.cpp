/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:05:28 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 14:13:58 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}
	
SuperMutant::SuperMutant(SuperMutant const &Cc) : Enemy(Cc) {
	*this = Cc;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}
	
SuperMutant::~SuperMutant() {
	std::cout << "Aaargh ..." << std::endl;
	return;
}

SuperMutant 	&SuperMutant::operator = (SuperMutant const &Cc) {
	this->_hp = Cc._hp;
	this->_type = Cc._type;
	return *this;
}

void 			SuperMutant::takeDamage(int p) {
	p = p - 3;
	this->_hp -= p;
	if (this->_hp < 0)
		this->_hp = 0;
}
