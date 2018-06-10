/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:32:24 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 15:00:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <tgmath.h>

std::string c2hex(unsigned char val)
{
	static const char*	digits = "0123456789ABCDEF";
	char				num[3];
	size_t				size = sizeof(num) - 1;
	std::string			ret;

	if (val == 0) {
		ret = "00";
		return ret;
	}
	if (val < 16) {
		ret = "0";
		ret += digits[val];
		return ret;
	}

	while (val)
	{
		num[--size] = digits[(val % 16)];
		val /= 16;
	}
	num[2] = 0;
	ret = num;
	return (ret);
}
