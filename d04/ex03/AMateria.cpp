/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:35:21 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 19:18:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <limits>

AMateria::AMateria(void): xp_(0) {
	return;
}

AMateria::AMateria(std::string const & type): xp_(0), _type(type) {
	return;
}

AMateria::~AMateria(void) {
	return;
}

AMateria::AMateria(AMateria const & Cc): xp_(Cc.xp_), _type(Cc._type) {
	return;
}

AMateria &AMateria::operator = (AMateria const &Cc) {
	this->xp_ = Cc.xp_;
	this->_type = Cc._type;
	return *this;
}

/*
void		AMateria::use(ICharacter&) {
	unsigned int tmp = this->xp_;
	this->xp_ += 10;
	if (this->xp_ < tmp)
		this->xp_ = std::numeric_limits<unsigned int>::max();;
	//(void)target;
}
*/
void AMateria::use(ICharacter&) {
	this->xp_ += 10;
}

std::string const & AMateria::getType() const {
	return (this->_type);
}

unsigned int AMateria::getXP() const {
	return (this->xp_);
}

void AMateria::setXP(unsigned int xp) {
	this->xp_ = xp;
}
