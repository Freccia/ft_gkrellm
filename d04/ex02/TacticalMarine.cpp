/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:45:20 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 15:19:15 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine() {
	std::cout << "Tactical Marine ready for battle" << std::endl;
	return;
}

TacticalMarine::TacticalMarine(TacticalMarine const &Cc) {
	*this = Cc;
	std::cout << "Tactical Marine ready for battle" << std::endl;
	return;
}

TacticalMarine::~TacticalMarine() {
	std::cout << "Aaargh ..." << std::endl;
	return;
}

TacticalMarine &TacticalMarine::operator=(TacticalMarine const &) {
	return *this;
}

ISpaceMarine	*TacticalMarine::clone() const {
	ISpaceMarine *clone = new TacticalMarine();
	return clone;
}

void			TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT !" <<std::endl;
}

void 			TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *" <<std::endl;
}

void 			TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *" <<std::endl;
}

