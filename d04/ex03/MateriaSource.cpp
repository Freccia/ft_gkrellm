/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:07:45 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 18:23:00 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _amount(0) {
	return;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < this->_amount; i++) {
		delete this->_inventory[i];
	}
	return;
}

MateriaSource::MateriaSource(MateriaSource const & Cc) : _amount(Cc._amount) {
	for (int i = 0; i < this->_amount; i++) {
		this->_inventory[i] = Cc._inventory[i]->clone();
	}
	return;
}

MateriaSource &		MateriaSource::operator = (MateriaSource const & Cc) {
	this->~MateriaSource();
	this->_amount = Cc._amount;
	for (int i = 0; i < this->_amount; i++) {
		this->_inventory[i] = Cc._inventory[i]->clone();
	}
	return *this;
}

void				MateriaSource::learnMateria(AMateria* materia) {
	if (this->_amount == 4)
		return ;
	this->_inventory[this->_amount] = materia->clone();
	(this->_amount)++;
}

AMateria*			MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_amount; i++) {
		if ((this->_inventory[i])->getType() == type) {
			return (this->_inventory[i])->clone();
		}
	}
	return NULL;
}
