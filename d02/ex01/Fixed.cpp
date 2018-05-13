/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:06:54 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 17:19:47 by lfabbro          ###   ########.fr       */
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

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointVal = n << _nBits;
	return;
}

Fixed::Fixed(float const f) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointVal = roundf(f);
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
	return _fixedPointVal;
}

void			Fixed::setRawBits(int const raw) {
	_fixedPointVal = raw;
	return;
}

int				Fixed::toInt(void) const {
	return _fixedPointVal >> _nBits;
}

float			Fixed::toFloat(void) const {
	float	f = _fixedPointVal;
	return f / (1 << _nBits);
}

std::ostream	&operator << (std::ostream &out, Fixed const &rop) {
	out << rop.getRawBits();
	return out;
}
