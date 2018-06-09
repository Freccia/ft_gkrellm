/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:32:24 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/09 15:44:53 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

template <typename I>
std::string n2hexstr(I w, size_t hex_len = sizeof(I) << 1)
{
	static const char* digits = "0123456789ABCDEF";
	std::string xs( hex_len, '0' );

	for (size_t i=0, j = (hex_len-1)*4 ; i < hex_len; ++i, j -= 4) {
		xs[i] = digits[ (w >> j) & 0x0f ];
	}
	return xs;
}

//template< typename T >
std::string nToHex( unsigned char i )
{
	std::stringstream stream;
	stream << "0x" 
		<< std::setfill ('0') << std::setw(sizeof(unsigned char)*2) 
		<< std::hex << i;
	return stream.str();
}
