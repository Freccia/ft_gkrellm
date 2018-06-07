/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:07:16 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/07 12:43:23 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <list>

template <typename T>
typename T::const_iterator	easyfind(T const & t, int n) {

	typename T::const_iterator found = std::find(t.begin(), t.end(), n);

	if (found == t.end())
		throw std::exception();
	return found;
}

#endif
