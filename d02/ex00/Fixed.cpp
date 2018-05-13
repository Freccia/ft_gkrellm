/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:06:54 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 16:40:02 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointVal(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &Cc) {
	std::cout << "Copy constructor called" << std::endl;
	*this = Cc;
	return;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed			&Fixed::operator = (Fixed const &rop) {
	std::cout << "Assignator operator called" << std::endl;
	if (this != &rop)
		_fixedPointVal = rop.getRawBits();
	return *this;
}

int				Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointVal;
}

void			Fixed::setRawBits(int const raw) {
	_fixedPointVal = raw;
	return;
}

std::ostream	&operator << (std::ostream &out, Fixed const &rop) {
	out << rop.getRawBits();
	return out;
}
