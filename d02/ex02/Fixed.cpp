/*
 ************************************************************************** */
/*
                                                                            */
/*
                                                        :::      ::::::::   */
/*
   Fixed.cpp                                          :+:      :+:    :+:   */
/*
                                                    +:+ +:+         +:+     */
/*
   By: lfabbro <>                                 +#+  +:+       +#+        */
/*
                                                +#+#+#+#+#+   +#+           */
/*
   Created: 2018/05/13 14:29:55 by lfabbro           #+#    #+#             */
/*
   Updated: 2018/05/13 14:30:02 by lfabbro          ###   ########.fr       */
/*
                                                                            */
/*
 ************************************************************************** */

#include "Fixed.hpp"

/*
**		Constructors Destructors
*/

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
	std::cout << "Assignation operator called" << std::endl;
	if (this != &Cc)
		_value = Cc.getRawBits();
	return *this;
}

/*
**		Comparison operators
*/

bool				operator == (Fixed const &) const{
	return _value == 
}

bool				operator != (Fixed const &) const{
}

bool				operator >= (Fixed const &) const{
}

bool				operator <= (Fixed const &) const{
}

bool				operator > (Fixed const &) const{
}

bool				operator < (Fixed const &) const{
}

/*
**		Arithmetic operators	
*/

Fixed				operator + (Fixed const &) const{
}

Fixed				operator - (Fixed const &) const{
}

Fixed				operator * (Fixed const &) const{
}

Fixed				operator / (Fixed const &) const{
}


/*
**		Increment/Decrement Pre/Post operators
*/

Fixed				&operator ++ () const{
}

Fixed				operator ++ (int) const{
}

Fixed				&operator -- () const{
}

Fixed				operator -- (int) const{
}


/*
**		Non-member functions
*/

Fixed				&min(Fixed &, Fixed &){
}

Fixed const			&min(Fixed const &, Fixed const &){
}

Fixed				&max(Fixed &, Fixed &){
}

Fixed const			&max(Fixed const &, Fixed const &){
}


/*
**		Non-member operators
*/

std::ostream	&operator << (std::ostream &out, Fixed const &f) {
	out << f.toFloat();
	return out;
}
