/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:42:05 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 12:48:10 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.class.hpp"

Pony::Pony(std::string _name, size_t _strenght, int _stamina, float _speed) {
	this->_name = _name;
	this->_strenght = _strenght;
	this->_stamina = _stamina;
	this->_speed = _speed;
	std::cout << "A Pony _named "<<_name<<" with _strenght "<<_strenght;
	std::cout << ", _stamina "<<_stamina<<" and _speed "<<_speed;
	std::cout << " has been created ";
	return;
}

Pony::~Pony(void) {
	return;
}

void	Pony::ponyPunch(void) {
	std::cout << this->_name << " gives you a punch with " << this->_strenght <<
	" _strenght!"<< std::endl;
}

void	Pony::ponyRun(void) {
	std::cout << this->_name << " runs away at " << this->_speed <<
	" Mph!"<< std::endl;
}

void	ponyOnTheHeap(
	std::string _name,
	size_t _strenght,
	int _stamina,
	float _speed)
{
	Pony	*P = new Pony(_name, _strenght, _stamina, _speed);

	std::cout << "on the heap!" << std::endl;
	(*P).ponyPunch();
	(*P).ponyRun();
	std::cout << "Pony address: " << P << std::endl;
	delete P;
}

void	ponyOnTheStack(
	std::string _name,
	size_t _strenght,
	int _stamina,
	float _speed)
{
	Pony	P = Pony(_name, _strenght, _stamina, _speed);

	std::cout << " on the stack!" << std::endl;
	P.ponyPunch();
	P.ponyRun();
	std::cout << "Pony address: " << &P << std::endl;
}
