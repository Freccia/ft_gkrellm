/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:08:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 19:07:49 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice"){
	return;
}

Ice::~Ice(void) {
	return;
}

/*
Ice::Ice(std::string const & type): AMateria(type) {
	return;
}
*/

Ice::Ice(Ice const & Cc): AMateria(Cc) {
	return;
}

Ice &Ice::operator = (Ice const &Cc) {
	this->AMateria::operator = (Cc);
	return *this;
}

void		Ice::use(ICharacter& target) {
	this->AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName()
		<< " *" << std::endl;
}

AMateria		*Ice::clone() const {
	Ice *materia = new Ice();
	materia->setXP(this->getXP());
	return materia;
}
