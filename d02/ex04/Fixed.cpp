/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:34:34 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/14 14:16:41 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
**		Constructors Destructors
*/

Fixed::Fixed(void): _value(0) {
	//std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &Cc) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = Cc;
	return;
}

Fixed::Fixed(int const n) {
	//std::cout << "Int constructor called" << std::endl;
	_value = n << _bits;
	return;
}

Fixed::Fixed(float const f) {
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _bits));
	//_value = floor(f * (1 << _bits));
	return;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
	return;
}


/*
**		Member functions
*/

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


/*
**		Operators
*/

Fixed			&Fixed::operator = (Fixed const &Cc) {
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &Cc)
		_value = Cc.getRawBits();
	return *this;
}

Fixed			&Fixed::operator = (int n) {
	//std::cout << "Assignation operator called" << std::endl;
	_value = n << _bits;
	return *this;
}

Fixed			&Fixed::operator = (float f) {
	//std::cout << "Assignation operator called" << std::endl;
	_value = roundf(f * (1 << _bits));
	return *this;
}


/*
**		Comparison operators
*/

bool				Fixed::operator == (Fixed const &rop) const {
	return this->_value == rop.getRawBits();
}

bool				Fixed::operator != (Fixed const &rop) const {
	return this->_value != rop.getRawBits();
}

bool				Fixed::operator >= (Fixed const &rop) const {
	return this->_value >= rop.getRawBits();
}

bool				Fixed::operator <= (Fixed const &rop) const {
	return this->_value <= rop.getRawBits();
}

bool				Fixed::operator > (Fixed const &rop) const {
	return this->_value > rop.getRawBits();
}

bool				Fixed::operator < (Fixed const &rop) const {
	return this->_value < rop.getRawBits();
}


/*
**		Arithmetic operators	
*/

Fixed				Fixed::operator + (Fixed const &rop) const {
	Fixed res;
	res._value = this->_value + rop.getRawBits();
	return res;
}

Fixed				Fixed::operator - (Fixed const &rop) const {
	Fixed res;
	res._value = this->_value - rop.getRawBits();
	return res;
}

Fixed				Fixed::operator * (Fixed const &rop) const {
	Fixed res;
	res.setRawBits(this->_value * rop.getRawBits() >> this->_bits);
	return res;
}

Fixed				Fixed::operator / (Fixed const &rop) const {
	Fixed res;
	if (rop.getRawBits() == 0)
		throw _division_by_zero();
	res.setRawBits((this->_value << this->_bits) / rop.getRawBits());
	return res;
}

Fixed				Fixed::operator - () const {
	Fixed res;
	res._value = -this->_value;
	return res;
}


/*
**		Increment/Decrement Pre/Post operators
*/

Fixed				&Fixed::operator ++ () {
	this->_value += 1;
	return *this;
}

Fixed				Fixed::operator ++ (int) {
	Fixed res(*this);
	operator++();
	return res;
}

Fixed				&Fixed::operator -- () {
	this->_value -= 1;
	return *this;
}

Fixed				Fixed::operator -- (int) {
	Fixed res(*this);
	operator--();
	return res;
}


/*
**		Non-member functions
*/

Fixed				&Fixed::min(Fixed &a, Fixed &b){
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

Fixed const			&Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

Fixed				&Fixed::max(Fixed &a, Fixed &b){
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}

Fixed const			&Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}


/*
**		Non-member operators
*/

std::ostream	&operator << (std::ostream &out, Fixed const &f) {
	out << f.toFloat();
	return out;
}
