/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:40:27 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/06 12:21:29 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

template <typename T>
void	iter(T *arr, size_t size, T (*f)(T))
{
	for(size_t i=0; i < size; i++) {
		f(arr[i]);
	}
}

template <typename T, typename F>
void	iter_bis(T *arr, size_t size, F (*f)(T))
{
	for(size_t i=0; i < size; i++) {
		f(arr[i]);
	}
}
