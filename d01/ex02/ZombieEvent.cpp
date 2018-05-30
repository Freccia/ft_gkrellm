/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:43:49 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/29 11:11:52 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) :_zombieType("walker"){
	return;
}

ZombieEvent::~ZombieEvent(void){
	return;
}

void			ZombieEvent::setZombieType(std::string type){
	this->_zombieType = type;
}

Zombie*			ZombieEvent::newZombie(std::string name){
	Zombie*		z;

	z = new Zombie();
	z->setZombieName(name);
	z->setZombieType(this->_zombieType);
	return z;
}

Zombie*			ZombieEvent::randomChump(void){
	std::string		names[] = {"Alfred", "John", "Jack", "Barbara", "Lucy", 
			"Cathrina", "Rose", "Lucius", "Roland", "Ron", "Ben", "Isabel",
			"William", "Grace", "Alice", "Bob", "Frank", "Francis", "Fred",
			"Philip", "Julie", "Margot", "Erika"};
	int				names_size = 23;
	int				random_name = rand() % names_size;
	Zombie*			zombie;
	//std::string		types[] = {"walker", "runner", "vomiter", "screamer"};
	//int				types_size = 4;
	//int				random_type = rand() % types_size;

	zombie = new Zombie();
	zombie->setZombieName(names[random_name]);
	zombie->setZombieType(this->_zombieType);
	//zombie->setZombieType(types[random_type]);
	zombie->announce();
	return zombie;
}
