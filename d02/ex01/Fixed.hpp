/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:32:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 17:18:21 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed {

private:
	int					_fixedPointVal;
	static int const	_nBits = 8;

public:
	Fixed();
	Fixed(Fixed const &);
	Fixed(int const);
	Fixed(float const);
	~Fixed();

	Fixed				&operator = (Fixed const &);
	int					getRawBits(void) const;
	void				setRawBits(int const);
	int					toInt(void) const;
	float				toFloat(void) const;

};

std::ostream			&operator << (std::ostream &, Fixed const &);

#endif
