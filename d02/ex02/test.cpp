/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 15:26:06 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/14 11:50:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int		main( void ) {
	Fixed a (15.3f);
	Fixed b ( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed c (-5.5f);
	Fixed d (0);

/*		Arithmetic Operations */
	std::cout << a + c << " | ";
	std::cout << a.toFloat() + c.toFloat() << std::endl;
	std::cout << a - c << " | ";
	std::cout << a.toFloat() - c.toFloat() << std::endl;
	std::cout << a / c << " | ";
	std::cout << a.toFloat() / c.toFloat() << std::endl;
	std::cout << a * c << " | ";
	std::cout << a.toFloat() * c.toFloat() << std::endl;
	std::cout << b * a << " | ";
	std::cout << b.toFloat() * a.toFloat() << std::endl;

/*		Decrement Operations */
	float	tmp = a.toFloat();
	std::cout << --a << " | ";
	std::cout << --tmp << std::endl;
	std::cout << a << " | ";
	std::cout << tmp << std::endl;
	std::cout << a-- << " | ";
	std::cout << tmp-- << std::endl;
	std::cout << a << " | ";
	std::cout << tmp << std::endl;

/*		Min/Max functions */
	std::cout << "max(" << a.toFloat() << ", " << c.toFloat() << ") = " <<
				Fixed::max( a, c ) << std::endl;
	std::cout << "min(" << a.toFloat() << ", " << c.toFloat() << ") = " <<
				Fixed::min( a, c ) << std::endl;

/*		Exceptions */
	std::cout << b / d << std::endl;

	return 0;
}
