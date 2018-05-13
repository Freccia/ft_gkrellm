/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:32:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 16:35:17 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

private:
	int					_fixedPointVal;
	static int const	_nFractBits = '8';

public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &);
	Fixed				&operator = (Fixed const &);
	int					getRawBits(void) const;
	void				setRawBits(int const);

};

std::ostream			&operator << (std::ostream &, Fixed const &);

#endif
