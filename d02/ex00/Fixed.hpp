/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 00:16:42 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/13 00:44:14 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <sstream>

class Fixed {

public:
	Fixed();
	Fixed(Fixed const &);
	~Fixed();
	int					getRawBits(void) const;
	void				setRawits(int const);
	Fixed				&operator = (Fixed const &);

private:
	int					_value;
	static int const	_bits;

};

std::ostream		&operator << (std::ostream &, Fixed const &);

#endif
