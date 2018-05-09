/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:55:13 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 15:22:29 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"


int		main(int ac, char **av)
{
	Zombie			stack_walker;
	Zombie*			heap_runner;
	Zombie*			heap_screamer;
	ZombieEvent		event;
	size_t			n_vomit = (ac > 1) ? atoi(av[1]) : 16;
	Zombie*			heap_vomiters[n_vomit];

	stack_walker.announce();

	event.setZombieType("runner");
	heap_runner = event.newZombie("Bolt");
	heap_runner->announce();

	event.setZombieType("screamer");
	heap_screamer = event.newZombie("Miley Cyrus");
	heap_screamer->announce();

	event.setZombieType("vomiter");
	for (size_t i=0; i < n_vomit; i++)
	{
		heap_vomiters[i] = event.randomChump();
	}
	for (size_t i=0; i < n_vomit; i++)
	{
		delete heap_vomiters[i];
	}
	delete heap_runner;
	delete heap_screamer;
	return 0;
}
