/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:43:55 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 16:00:29 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) :_type("walker"),_name("Unnamed"){
	return;
}

Zombie::~Zombie(void){
	std::cout << this->_name << "(" << this->_type << ")";
	std::cout << " died! ... oh no.. now he crawls!" << std::endl;
	return;
}

std::string		Zombie::getName(void){
	return this->_name;
}

std::string		Zombie::getType(void){
	return this->_type;
}

void			Zombie::setName(std::string _name){
	this->_name = _name;
}

void			Zombie::setType(std::string _type){
	this->_type = _type;
}

void			Zombie::announce(void){
	std::cout << "<" << this->_name <<" ("<< this->_type << ")> ";
	if (this->_type == "walker")
		std::cout << "Walks towards you to eat your brain!" << std::endl;
	else if (this->_type == "runner")
		std::cout << "Runs towards you to dismember your body!" << std::endl;
	else if (this->_type == "vomiter")
		std::cout << "Vomits in your direction! BBllaaaargghh!" << std::endl;
	else if (this->_type == "screamer")
		std::cout << "Brrrrraaaaaainnnnsss !" << std::endl;
	else
		std::cout << "You must run!" << std::endl;
}
