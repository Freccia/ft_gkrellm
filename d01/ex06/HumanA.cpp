/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:08:40 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 10:52:29 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon){
	return;
}

HumanA::~HumanA(){
	return;
}

void		HumanA::attack(){
	std::cout << this->_name << " attack with his " <<
		this->_weapon.getType() << std::endl;
}
