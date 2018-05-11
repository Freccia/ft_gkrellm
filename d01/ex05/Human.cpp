/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:04:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 19:22:02 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() {
	return;
}

Human::~Human() {
	return;
}

std::string		Human::identify() {
	return _brain.identify();
}

Brain const		&Human::getBrain() const {
	return _brain;
}
