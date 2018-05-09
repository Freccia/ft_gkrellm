/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:42:12 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 16:28:01 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int		ZombieHorde::_nbHordes = 0;

ZombieHorde::ZombieHorde(int n) : _zombieHordeType("Bonecrusher")
{
	_horde = new Zombie[n];

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "A horde of " << n << " insanes " << _zombieHordeType <<
				" zombies is created, prepare yourselves!" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	for (int i=0; i < n; i++)
	{
		_randomName(&_horde[i]);
	}
	_size = n;
	ZombieHorde::_nbHordes++;
	return;
}

ZombieHorde::~ZombieHorde(void)
{
	ZombieHorde::_nbHordes--;
	delete []_horde;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "A horde of " << _size << " insanes " << _zombieHordeType <<
				" zombies is destroyed, fiiiuuuff !!" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	return;
}

void			ZombieHorde::setZombieHordeType(std::string type)
{
	for (int i=0; i < _size; i++)
	{
		_horde[i].setType(type);
	}
}

void			ZombieHorde::_randomName(Zombie* zombie)
{
	std::string		names[] = {"Alfred", "John", "Jack", "Barbara", "Lucy", 
			"Cathrina", "Rose", "Lucius", "Roland", "Ron", "Ben", "Isabel",
			"William", "Grace", "Alice", "Bob", "Frank", "Francis", "Fred",
			"Philip", "Julie", "Margot", "Erika"};
	int				names_size = 23;
	int				random_name = rand() % names_size;

	zombie->setName(names[random_name]);
	zombie->setType(_zombieHordeType);
	zombie->announce();
}

int				ZombieHorde::getNbHordes(void)
{
	return ZombieHorde::_nbHordes;
}
