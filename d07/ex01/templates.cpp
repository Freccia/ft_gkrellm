/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:40:27 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/05 16:18:57 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

template <typename T> // this is the template parameter declaration
T		max(T x, T y)
{
	return (x > y) ? x : y;
}

template <typename T>
T		min(T x, T y)
{
	return (x < y) ? x : y;
}

template <typename T>
void	swap(T &x, T &y)
{
	T	k;
	T	j;

	k = y;
	j = x;
	x = k;
	y = j;
}

/*
template <typename T, typename F>
void	iter(T val, size_t size, F funk)
{
	for(size_t i=0; i < size; i++)
	{
		funk(val[i]);
	}
}
*/

template<typename T, typename F>
void	iter(T *arr, ssize_t size, F (*f)(T &)) {
	for (int i = 0; i < size; i++) {
		f(arr[i]);
	}
}
