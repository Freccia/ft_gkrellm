/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:18:13 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 15:20:09 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator() {
	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &Cc) {
	*this = Cc;
	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::~AssaultTerminator() {
	std::cout << "I’ll be back ..." << std::endl;
	return;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &Cc) {
	(void)Cc;
	return *this;
}

ISpaceMarine	*AssaultTerminator::clone() const {
	ISpaceMarine *clone = new AssaultTerminator();
	return clone;
}

void			AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT !" <<std::endl;
}

void 			AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" <<std::endl;
}

void 			AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" <<std::endl;
}

