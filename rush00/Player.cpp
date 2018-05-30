/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:13:01 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/30 17:59:37 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) {
}

Player::~Player(void) {
}

Player::Player(Player const &Cc) {
	*this = Cc;
}

Player				&Player::operator = (Player const &Cc) {
	_lifes = Cc.getLifes();
	_shape = Cc.getShape();
	return *this;
}

unsigned int		Player::getLifes(void) const {
	return this->_lifes;
}

std::string			Player::getShape(void) const {
	return this->_shape;
}

int					Player::getShapeSize(void) const {
	return this->_shape.size();
}

int					Player::getPosX(void) const {
	return this->_pos.x;
}

int					Player::getPosY(void) const {
	return this->_pos.y;
}

/*
s_position	Player::getPosition(void) {
	return this->pos;
}
*/

bool				Player::setLifes(int lifes) {
	this->_lifes = lifes;
	return true;
}


bool				Player::setShape(std::string shape) {
	this->_shape = shape;
	return true;
}

bool				Player::setPosition(int x, int y) {
	this->_pos.x = x;
	this->_pos.y = y;
	return true;
}
