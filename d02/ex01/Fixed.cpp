/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 00:21:49 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/13 13:29:53 by lfabbro          ###   ########.fr       */
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

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	_value = n << _bits;
	return;
}

Fixed::Fixed(float const f) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _bits));
	//_value = floor(f * (1 << _bits));
	return;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	return;
}

int				Fixed::getRawBits(void) const {
	return _value;
}

void			Fixed::setRawBits(int const raw) {
	_value = raw;
	return;
}

int				Fixed::toInt(void) const {
	return _value >> _bits;
}

float			Fixed::toFloat(void) const {
	float	f = _value;
	return f / (1 << _bits);
}

Fixed			&Fixed::operator = (Fixed const &Cc) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &Cc)
		_value = Cc.getRawBits();
	return *this;
}

std::ostream	&operator << (std::ostream &out, Fixed const &f) {
	out << f.toFloat();
	return out;
}
