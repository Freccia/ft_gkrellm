/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:06:54 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/13 12:15:25 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &Cc) {
	std::cout << "Copy constructor called" << std::endl;
	*this = Cc;
	return;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int				Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void			Fixed::setRawits(int raw) {
	_value = raw;
	return;
}

Fixed			&Fixed::operator = (Fixed const &Cc) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &Cc)
		_value = Cc.getRawBits();
	return *this;
}

std::ostream	&operator << (std::ostream &out, Fixed const &f) {
	out << f.getRawBits();
	return out;
}
