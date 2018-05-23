/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:12:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 14:13:32 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
	return;
}
	
RadScorpion::RadScorpion(RadScorpion const &Cc) : Enemy(Cc) {
	*this = Cc;
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion 	&RadScorpion::operator = (RadScorpion const &Cc) {
	this->_hp = Cc._hp;
	this->_type = Cc._type;
	return *this;
}
