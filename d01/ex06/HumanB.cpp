/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:12:37 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 11:01:32 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name){
	return;
}

HumanB::~HumanB(){
	return;
}

void		HumanB::attack(){
	std::cout << this->_name << " attack with his " <<
		this->_weapon->getType() << std::endl;
}

void		HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
}
