/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:32:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/13 12:17:27 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <sstream>

class Fixed {

private:
	int					_value;
	static int const	_bits = 8;

public:
	Fixed();
	Fixed(Fixed const &);
	~Fixed();
	int					getRawBits(void) const;
	void				setRawits(int const);
	Fixed				&operator = (Fixed const &);
};

std::ostream		&operator << (std::ostream &, Fixed const &);

#endif
