/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:32:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/14 14:15:59 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <sstream>
#include <cmath>

class Fixed {

private:
	int					_value;
	static int const	_bits = 8;

public:
	Fixed();
	Fixed(Fixed const &);
	Fixed(int const);
	Fixed(float const);
	~Fixed();
	int					getRawBits(void) const;
	void				setRawBits(int const);
	int					toInt(void) const;
	float				toFloat(void) const;

	/*		Assignation operators	*/
	Fixed				&operator = (Fixed const &);
	Fixed				&operator = (int);
	Fixed				&operator = (float);

	/*		Comparison operators	*/
	bool				operator == (Fixed const &) const;
	bool				operator != (Fixed const &) const;
	bool				operator >= (Fixed const &) const;
	bool				operator <= (Fixed const &) const;
	bool				operator > (Fixed const &) const;
	bool				operator < (Fixed const &) const;

	/*		Arithmetic operators	*/
	Fixed				operator + (Fixed const &) const;
	Fixed				operator - (Fixed const &) const;
	Fixed				operator * (Fixed const &) const;
	Fixed				operator / (Fixed const &) const;
	Fixed				operator - () const;

	/*		Increment/Decrement Pre/Post operators	*/
	Fixed				&operator ++ ();
	Fixed				operator ++ (int);
	Fixed				&operator -- ();
	Fixed				operator -- (int);

	/*		Non-member functions	*/
	static Fixed				&min(Fixed &, Fixed &);
	static Fixed const			&min(Fixed const &, Fixed const &);
	static Fixed				&max(Fixed &, Fixed &);
	static Fixed const			&max(Fixed const &, Fixed const &);

	/*		Exceptions*/
	struct _division_by_zero : std::exception {};
};

std::ostream		&operator << (std::ostream &, Fixed const &);

#endif
