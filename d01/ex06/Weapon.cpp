/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 09:59:13 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 10:57:40 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapontype): type(weapontype){
	return;
}

Weapon::~Weapon(void){
	return;
}

std::string const &	Weapon::getType() const {
	return this->type;
}

void				Weapon::setType(std::string weapontype){
	this->type = weapontype;
}
