/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:42:05 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 12:09:10 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.class.hpp"

Pony::Pony(std::string name, size_t strenght, int stamina, float speed) {
	this->name = name;
	this->strenght = strenght;
	this->stamina = stamina;
	this->speed = speed;
	std::cout << "A Pony named "<<name<<" with strenght "<<strenght;
	std::cout << ", stamina "<<stamina<<" and speed "<<speed;
	std::cout << " has been created ";
	return;
}

Pony::~Pony(void) {
	return;
}

void	Pony::ponyPunch(void) {
	std::cout << this->name << " gives you a punch with " << this->strenght <<
	" strenght!"<< std::endl;
}

void	Pony::ponyRun(void) {
	std::cout << this->name << " runs away at " << this->speed <<
	" Mph!"<< std::endl;
}

void	ponyOnTheHeap(
	std::string name,
	size_t strenght,
	int stamina,
	float speed)
{
	Pony	*P = new Pony(name, strenght, stamina, speed);

	std::cout << "on the heap!" << std::endl;
	(*P).ponyPunch();
	(*P).ponyRun();
	std::cout << "Pony address: " << P << std::endl;
	delete P;
}

void	ponyOnTheStack(
	std::string name,
	size_t strenght,
	int stamina,
	float speed)
{
	Pony	P = Pony(name, strenght, stamina, speed);

	std::cout << " on the stack!" << std::endl;
	P.ponyPunch();
	P.ponyRun();
	std::cout << "Pony address: " << &P << std::endl;
}
