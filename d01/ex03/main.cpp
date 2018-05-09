/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:55:13 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 16:23:57 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"


int		main(int ac, char **av)
{
	ZombieHorde		*heap_horde;
	ZombieHorde		stack_horde(5);

	heap_horde = new ZombieHorde((ac > 1) ? atoi(av[1]) : 16);
	delete heap_horde;
	return 0;
}
