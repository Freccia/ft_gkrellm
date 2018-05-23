/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:57:13 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 13:57:50 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() {
	return;
}

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type) {
	return;
}
	
Enemy::Enemy(Enemy const &Cc) {
	*this = Cc;
	return;
}

Enemy::~Enemy() {
	return;
}

Enemy 	&Enemy::operator = (Enemy const &Cc) {
	this->_hp = Cc._hp;
	this->_type = Cc._type;
	return *this;
}

std::string		Enemy::getType() const {
	return this->_type;
}

int 			Enemy::getHP() const {
	return this->_hp;
}

void 			Enemy::takeDamage(int p) {
	this->_hp -= p;
	if (this->_hp < 0)
		this->_hp = 0;
}
