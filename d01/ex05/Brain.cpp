/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:59:32 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 19:25:34 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(): _weight(16),_iq(52),_imagination(40){
	_weight = 16;
	_iq = 52;
	_imagination = 40;
	return;
}

Brain::~Brain(){
	return;
}

std::string		Brain::identify() const {
	std::stringstream str;
	str << (void const *)this;
	return str.str();
}
