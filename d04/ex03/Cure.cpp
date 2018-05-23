/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:51:10 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 17:53:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	return;
}

Cure::Cure(Cure const & src) : AMateria(src) {
	return;
}

Cure::~Cure(void) {
	return;
}

Cure			&Cure::operator = (Cure const & Cc) {
	this->AMateria::operator = (Cc);
	return *this;
}

AMateria*		Cure::clone() const {
	Cure *materia = new Cure();
	materia->setXP(this->getXP());
	return materia;
}

void			Cure::use(ICharacter& target) {
	this->AMateria::use(target);
	std::cout << "*  heals " << target.getName() << "'s wounds *" << std::endl;
}
