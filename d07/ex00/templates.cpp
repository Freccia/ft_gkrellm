/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:25:39 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/05 10:35:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
